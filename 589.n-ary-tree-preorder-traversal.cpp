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
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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
    vector<int> preorder(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<int> res;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *n = st.top();
            st.pop();
            res.push_back(n->val);
            if (!n->children.empty())
            {
                for (int i = n->children.size() - 1; i >= 0; --i)
                {
                    st.push(n->children[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
