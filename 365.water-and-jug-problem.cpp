#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

// @lc code=start
class Solution
{
  public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        if (jug1Capacity + jug2Capacity < targetCapacity)
        {
            return false;
        }
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            if (visited.count(p))
            {
                continue;
            }
            if (p.first == targetCapacity || p.second == targetCapacity || p.first + p.second == targetCapacity)
            {
                return true;
            }
            q.push({jug1Capacity, p.second});
            q.push({p.first, jug2Capacity});
            q.push({0, p.second});
            q.push({p.first, 0});
            if (p.first + p.second >= jug2Capacity)
            {
                q.push({p.first + p.second - jug2Capacity, jug2Capacity});
            }
            else
            {
                q.push({0, p.first + p.second});
            }
            if (p.first + p.second >= jug1Capacity)
            {
                q.push({jug1Capacity, p.first + p.second - jug1Capacity});
            }
            else
            {
                q.push({p.first + p.second, 0});
            }
            visited.insert(p);
        }
        return false;
    }
};
// @lc code=end
