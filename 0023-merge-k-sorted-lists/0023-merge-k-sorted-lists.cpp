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

struct
    {
        bool operator()(const ListNode *a, const ListNode *b) const { return a->val < b->val; }
    }
    customLess;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()== 0) return nullptr;
        vector<ListNode*> candidates = {};
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
            {
                candidates.push_back(lists[i]);
            };
        };
        if (candidates.size() == 0) return nullptr;
        ListNode *first, *last;
        sort(candidates.begin(), candidates.end(), customLess);
        first = last = candidates[0];
        while(true)
        {
            candidates.erase(candidates.begin());
            if (last->next != nullptr)
            {
                candidates.insert(lower_bound(candidates.begin(), candidates.end(), last->next, customLess), last->next);
            }
            if (candidates.size() == 0) break;
            last->next = candidates[0];
            last = candidates[0];
        };
        return first;
    }
};