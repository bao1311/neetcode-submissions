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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        auto cmp = [](ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        };

        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        for (auto l : lists)
        {
            if (l != nullptr)
                pq.push(l);
        }
        while (pq.size())
        {
            ListNode* temp = pq.top();
            cur->next = new ListNode(pq.top()->val);
            temp = temp->next;
            if (temp)
                pq.push(temp);
            cur = cur->next;
            pq.pop();
        }
        return dummy->next;
    }
};
