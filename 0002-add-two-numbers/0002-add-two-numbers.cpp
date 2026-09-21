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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        while (true) {
            if (p1 != nullptr) carry += p1->val;
            if (p2 != nullptr) carry += p2->val;
            curr->val = carry % 10;
            carry /= 10;
            if (p1 != nullptr) p1 = p1->next;
            if (p2 != nullptr) p2 = p2->next;
            if ((p1 == nullptr) && (p2 == nullptr) && (carry == 0)) return res; else {
                curr->next = new ListNode(carry);
                curr = curr->next;
            }
        }
    }
};
