// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* myhead = new Node(head->val);
        Node *curr = head, *mycurr = myhead;
        while (curr->next != nullptr) {
            mycurr->next = new Node(curr->next->val);
            curr = curr->next;
            mycurr = mycurr->next;
        }
        curr = head;
        mycurr = myhead;
        while (curr != nullptr) {
            if (curr->random == nullptr)
                continue;
            Node *curr2 = head, *mycurr2 = myhead;
            while (curr2 != curr->random) {
                curr2 = curr2->next;
                mycurr2 = mycurr2->next;
            }
            mycurr->random = mycurr2;
            curr = curr->next;
            mycurr = mycurr->next;
        }
        return myhead;
    }
};