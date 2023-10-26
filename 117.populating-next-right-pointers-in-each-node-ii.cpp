#include <bits/stdc++.h>
using namespace std;
class Node
{
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};
/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
  public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        else
        {
            queue<Node *> q1;
            queue<Node *> q2;
            q1.push(root);
            while (!q1.empty())
            {
                while (!q1.empty())
                {
                    Node *n = q1.front();
                    q1.pop();
                    if (!q1.empty())
                    {
                        n->next = q1.front();
                    }
                    else
                    {
                        n->next = nullptr;
                    }
                    if (n->left != nullptr)
                    {
                        q2.push(n->left);
                    }
                    if (n->right != nullptr)
                    {
                        q2.push(n->right);
                    }
                }
                swap(q1, q2);
            }
            return root;
        }
    }
};
// @lc code=end
