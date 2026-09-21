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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* tail = head->next;
        ListNode* pretail = head;
        while (tail != nullptr) {
            ListNode* newtail = tail->next;
            ListNode* curr = head;
            ListNode* prev;
            while (curr != tail && curr->val < tail->val) {
                prev = curr;
                curr = curr->next;
            }
            if (curr == head) {
                tail->next = head;
                head = tail;
                tail = newtail;
                pretail->next = newtail;
                continue;
            }
            if (curr == tail) {
                pretail = tail;
                tail = newtail;
                continue;
            }
            prev->next = tail;
            tail->next = curr;
            tail = newtail;
            pretail->next = newtail;
        }
        return head;
    }
};