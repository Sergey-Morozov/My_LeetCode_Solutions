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
    struct rec {
        int val;
        int ind;
    };
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> answer{0};
        stack<rec> s;
        int i = 0;
        s.push({head->val, i});
        while (head->next != nullptr) {
            i++;
            head = head->next;
            while (!s.empty() && (s.top().val < head->val)) {
                answer[s.top().ind] = head->val;
                s.pop();
            }
            s.push({head->val, i});
            answer.push_back(0);
        }
        return answer;
    }
};