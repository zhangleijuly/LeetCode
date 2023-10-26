#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution
{
  public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3)
        {
            return false;
        }
        visited = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
        return dp(s1, 0, s2, 0, s3);
    }
    bool dp(string &s1, int idx1, string &s2, int idx2, string &s3)
    {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (idx1 + idx2 == l3)
        {
            return true;
        }
        if (visited[idx1][idx2] != -1)
        {
            return visited[idx1][idx2] == 1 ? true : false;
        }

        bool res = false;
        if (idx1 < l1 && s1[idx1] == s3[idx1 + idx2])
        {
            res = dp(s1, idx1 + 1, s2, idx2, s3);
        }
        if (idx2 < l2 && s2[idx2] == s3[idx1 + idx2])
        {
            res = res || dp(s1, idx1, s2, idx2 + 1, s3);
        }
        visited[idx1][idx2] = res == true ? 1 : 0;
        return res;
    }

  private:
    vector<vector<int>> visited;
};
// @lc code=end
