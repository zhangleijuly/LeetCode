#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        string s;
        while (x > 0)
        {
            s.push_back('0' + x % 10);
            x = x / 10;
        }
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
};
// @lc code=end
