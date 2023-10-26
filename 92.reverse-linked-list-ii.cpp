#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

class Solution
{
  public:
    ListNode *successor;
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        successor = nullptr;
        if (left == 1)
        {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
    ListNode *reverseN(ListNode *head, int n)
    {
        if (n == 1)
        {
            successor = head->next;
            return head;
        }
        ListNode *last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }
};
// @lc code=end
