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
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(101, head);
        ListNode *slow = dummy, *fast = head;
        while (fast != nullptr)
        {
            if (fast->next != nullptr)
            {
                if (fast->next->val != fast->val)
                {
                    slow->next = fast;
                    slow = slow->next;
                    fast = fast->next;
                }
                else
                {
                    int v = fast->val;
                    while (fast != nullptr)
                    {
                        if (fast->val == v)
                        {
                            fast = fast->next;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            }
        }
        slow->next = nullptr;
        return dummy->next;
    }
};
// @lc code=end
