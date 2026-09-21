// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list2 == nullptr)
            return list1;
        if (list1 == nullptr)
            return list2;
        ListNode *curr, *head, *p1 = list1, *p2 = list2;
        if (p1->val < p2->val) {
            head = curr = p1;
            p1 = p1->next;
        } else {
            head = curr = p2;
            p2 = p2->next;
        }
        for (;;) {
            if (p1 == nullptr) {
                while (p2 != nullptr) {
                    curr->next = p2;
                    p2 = p2->next;
                    curr = curr->next;
                }
                return head;
            } else if (p2 == nullptr) {
                while (p1 != nullptr) {
                    curr->next = p1;
                    curr = curr->next;
                    p1 = p1->next;
                }
                return head;
            } else {
                if (p1->val < p2->val) {
                    curr->next = p1;
                    p1 = p1->next;
                } else {
                    curr->next = p2;
                    p2 = p2->next;
                }
                curr = curr->next;
            }
        }
    }
};