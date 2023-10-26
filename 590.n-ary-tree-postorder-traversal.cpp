#include <bits/stdc++.h>
using namespace std;
class Node
{
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
  public:
    vector<int> postorder(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<int> res;
        stack<Node *> st;
        stack<int> st2;
        st.push(root);
        while (!st.empty())
        {
            Node *n = st.top();
            st.pop();
            st2.push(n->val);
            if (!n->children.empty())
            {
                for (int i = 0; i < n->children.size(); ++i)
                {
                    st.push(n->children[i]);
                }
            }
        }
        while (!st2.empty())
        {
            res.push_back(st2.top());
            st2.pop();
        }
        return res;
    }
};
// @lc code=end
