#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int res = 0, start = 0, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    start = i + 1;
                }
                else
                {
                    st.pop();
                    if (st.empty())
                    {
                        res = max(res, i - start + 1);
                    }
                    else
                    {
                        res = max(res, i - st.top());
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
