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
        if (!head->next)
            return;
        ListNode* n1 = head;
        ListNode* n2 = head->next;
        // find mid point
        while (n1 && n2 && n2->next)
        {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        // go in to the second half
        ListNode* temp = n1->next;
        n1->next = nullptr;
        // n1 at second half
        n1 = temp;
        cout << "n1 val: " << n1->val << '\n';
        ListNode* prev = nullptr;
        ListNode* nxt = n1->next;
        while (n1)
        {
            nxt = n1->next;
            n1->next = prev;
            prev = n1;
            n1 = nxt;
        }
        n1 = prev;
        temp = head;
        // while (temp)
        // {
        //     cout << temp->val << ' ';
        //     temp = temp->next;
        // }
        while (temp && n1)
        {
            nxt = temp->next;
            ListNode* n2 = n1->next;
            n1->next = nxt;
            temp->next = n1;
            temp= nxt;
            n1 = n2;
        }
    }
};
