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
        ListNode* cur = head;
        for (int i = 0; i < k; ++i)
        {
            if (!cur)
                return head;
            cur = cur->next;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;
        for (int i = 0; i < k; ++i)
        {
            // cout << "head val is: " << head->val << '\n';
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        temp->next = reverseKGroup(head,k);
        return prev;
        
    }
};
