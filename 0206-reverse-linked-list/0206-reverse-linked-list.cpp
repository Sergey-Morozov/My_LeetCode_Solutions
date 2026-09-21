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
    ListNode* reverseOneStep(ListNode* curr, ListNode* prev) {
        ListNode* res;
        if (curr->next != nullptr)
            res = reverseOneStep(curr->next, curr);
        else {
            res = curr;
        }
        curr->next = prev;
        return res;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* res = reverseOneStep(head->next, head);
        head->next = nullptr;
        return res;
    }
};