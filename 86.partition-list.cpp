#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
  public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *p1 = dummy1, *p2 = dummy2;
        ListNode *p = head;
        while (p != nullptr)
        {
            if (p->val >= x)
            {
                p2->next = p;
                p2 = p2->next;
            }
            else
            {
                p1->next = p;
                p1 = p1->next;
            }
            ListNode *tmp = p->next;
            p->next = nullptr;
            p = tmp;
        }
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
// @lc code=end
