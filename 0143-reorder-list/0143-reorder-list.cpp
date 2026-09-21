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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        vector<ListNode*> all(50000, nullptr);
        ListNode *curr = head;
        int n = 0;
        do {
            all[n] = curr;
            curr = curr->next;
            n++;
        } while (curr != nullptr);
        int i = 0;
        n--;
        curr = head;
        while (i < n) {
            curr->next = all[n];
            n--;
            curr = curr->next;
            i++;
            if (i > n)
                break;
            curr->next = all[i];
            curr = curr->next;
        }
        curr->next = nullptr;
        return;
    }
};