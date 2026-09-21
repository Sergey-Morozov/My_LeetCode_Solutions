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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> group(k);
        ListNode* thead = head;
        ListNode* prev = nullptr;
        while (true) {
            ListNode* runner = thead;
            for (int i = 0; i < k; i++) {
                if (runner == nullptr) return head;
                group[k - i - 1] = runner;
                runner = runner->next;
            };
            if (prev == nullptr) {
                head = group[0];
            } else prev->next = group[0];
            for (int i = 0; i < k - 1; i++) {
                group[i]->next = group[i + 1];
            };
            group[k - 1]->next = runner;
            thead = runner; 
            prev = group[k - 1];
        }
    }
};