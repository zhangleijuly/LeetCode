#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution
{
  public:
    int longestSubstring(string s, int k)
    {
        int res = 0;
        if (s.size() < k)
        {
            return res;
        }
        vector<int> cnt(26, 0);
        for (char c : s)
        {
            ++cnt[c - 'a'];
        }
        // 遍历所有以r结尾的字符串
        for (int r = k - 1; r < s.size(); ++r)
        {
            // 如果r处字符个数不到k个一定不满足
            if (cnt[s[r] - 'a'] < k)
            {
                r += k - 1;
                continue;
            }
            // 连续相同字符找到最后一个
            while (r < s.size() - 1 && s[r] == s[r + 1])
            {
                ++r;
            }
            // 向左找到第一个出现次数少于k的字符，确定搜索范围
            int l;
            for (l = r; l >= 0; --l)
            {
                if (cnt[s[l] - 'a'] < k)
                {
                    break;
                }
            }
            l = l + 1;
            // 剪枝
            if (res > r - l + 1)
            {
                continue;
            }
            // 遍历l到r以r结尾的所有子串，判断是否满足条件并更新结果。
            vector<int> subcnt(26, 0);
            for (int i = r; i >= l; --i)
            {
                if (++subcnt[s[i] - 'a'] < k)
                {
                    continue;
                }
                else
                {
                    // 剪枝
                    if (res > r - i + 1)
                    {
                        continue;
                    }
                    bool flag = true;
                    for (int j = 0; j < 26; ++j)
                    {
                        if (subcnt[j] != 0 && subcnt[j] < k)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        res = max(res, r - i + 1);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
