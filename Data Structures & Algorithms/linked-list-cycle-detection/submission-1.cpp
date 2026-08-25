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
    bool hasCycle(ListNode* head) {
        if (!head)
            return false;
        ListNode* h1 = head;
        ListNode* h2 = head->next;

        while (h1 && h2 && h2->next)
        {
            if (h1 == h2)
                return true;
            h1 = h1->next;
            h2 = h2->next->next;
        }
        return false;
        
    }
};
