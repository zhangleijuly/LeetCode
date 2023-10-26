#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution
{
  public:
    int minAddToMakeValid(string s)
    {
        int left = 0;
        int right = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                ++right;
            }
            if (c == ')')
            {
                if (--right == -1)
                {
                    right = 0;
                    ++left;
                }
            }
        }
        return left + right;
    }
};
// @lc code=end
