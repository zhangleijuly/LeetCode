#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1541 lang=cpp
 *
 * [1541] Minimum Insertions to Balance a Parentheses String
 */

// @lc code=start
class Solution
{
  public:
    int minInsertions(string s)
    {
        int left = 0, right = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                right += 2;
                // 为避免"()()))"的情况输出0，作出如下处理
                if (right % 2 == 1)
                {
                    ++left;
                    --right;
                }
            }
            if (c == ')')
            {
                if (--right == -1)
                {
                    ++left;
                    right = 1;
                }
            }
        }
        return left + right;
    }
};
// @lc code=end
