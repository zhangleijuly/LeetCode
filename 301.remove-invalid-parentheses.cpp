#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution
{
  public:
    vector<string> removeInvalidParentheses(string s)
    {
        if (isValid(s))
        {
            return {s};
        }
        // 移除左侧的右括号和右侧的左括号
        for (auto it = s.begin(); it < s.end(); ++it)
        {
            if (*it == ')')
            {
                s.erase(it);
                --it;
            }
            else if (*it == '(')
            {
                break;
            }
        }
        if (!s.empty())
        {
            for (auto it = s.end() - 1; it >= s.begin(); --it)
            {
                if (*it == '(')
                {
                    s.erase(it);
                }
                else if (*it == ')')
                {
                    break;
                }
            }
        }
        vector<string> res;
        // 计算至少需要删除多少左括号和右括号
        int l = 0, r = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                ++l;
            }
            else if (c == ')')
            {
                if (l == 0)
                {
                    ++r;
                }
                else
                {
                    --l;
                }
            }
        }
        dfs(s, 0, l, r, res);
        return res;
    }
    bool isValid(string s)
    {
        int cnt = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                ++cnt;
            }
            else if (c == ')')
            {
                if (--cnt < 0)
                {
                    return false;
                }
            }
        }
        return cnt == 0;
    }
    void dfs(string &s, int cur, int l, int r, vector<string> &res)
    {
        if (l == 0 && r == 0)
        {
            if (isValid(s))
            {
                res.push_back(s);
            }
            return;
        }

        for (int i = cur; i < s.size(); ++i)
        {
            // 剪枝，连续括号中每次搜索只删除第一个
            if (i != cur && s[i] == s[i - 1])
            {
                continue;
            }
            // 删除一个括号
            if (s[i] == '(' && l > 0)
            {
                string tmp = s;
                tmp.erase(i, 1);
                dfs(tmp, i, l - 1, r, res);
            }
            else if (s[i] == ')' && r > 0)
            {
                string tmp = s;
                tmp.erase(i, 1);
                dfs(tmp, i, l, r - 1, res);
            }
        }
    }
};
// @lc code=end
