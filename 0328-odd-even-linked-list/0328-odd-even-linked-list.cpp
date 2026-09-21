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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        ListNode* odds = head;
        ListNode* two = head->next;
        ListNode* evens = two;
        while (true) {
            if (evens->next == nullptr)
                break;
            else {
                odds->next = evens->next;
                odds = odds->next; 
            }
            if (odds->next == nullptr)
                break;
            else {
                evens->next = odds->next;
                evens = evens->next; 
            }
        }
        odds->next = two;
        evens->next = nullptr;
        return head;
    }
};