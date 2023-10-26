#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class FenwickTree
{
  private:
    vector<int> preSum;
    static inline int lowbit(int x)
    {
        return x & -x;
    }

  public:
    FenwickTree(int n) : preSum(n + 1, 0) {}
    void update(int i, int delta)
    {
        while (i < preSum.size())
        {
            preSum[i] += delta;
            i += lowbit(i);
        }
    }
    int query(int i) const
    {
        int sum = 0;
        while (i > 0)
        {
            sum += preSum[i];
            i -= lowbit(i);
        }
        return sum;
    }
};

class Solution
{
  public:
    vector<int> countSmaller(vector<int> &nums)
    {
        set<int> sorted(nums.begin(), nums.end());
        unordered_map<int, int> ranks;
        int rank = 0;
        for (int num : sorted)
        {
            ranks[num] = ++rank;
        }
        vector<int> res;
        FenwickTree tree(rank);
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            res.push_back(tree.query(ranks[nums[i]] - 1));
            tree.update(ranks[nums[i]], 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
