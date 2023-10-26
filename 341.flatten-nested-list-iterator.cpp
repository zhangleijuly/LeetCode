#include <bits/stdc++.h>
using namespace std;
class NestedInteger
{
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    const vector<NestedInteger> &getList() const;
};
/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
  public:
    vector<int> m_list;
    int cur;

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        cur = 0;
        for (NestedInteger ni : nestedList)
        {
            flatten(ni);
        }
    }

    void flatten(NestedInteger ni)
    {
        if (ni.isInteger())
        {
            m_list.push_back(ni.getInteger());
        }
        else
        {
            vector<NestedInteger> nl = ni.getList();
            for (NestedInteger i : nl)
            {
                flatten(i);
            }
        }
    }

    int next()
    {
        return m_list[cur++];
    }

    bool hasNext()
    {
        return cur < m_list.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
