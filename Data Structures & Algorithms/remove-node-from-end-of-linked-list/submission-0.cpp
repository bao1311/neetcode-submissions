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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while (temp)
        {
            temp = temp->next;
            len += 1;
        }
        cout << len << '\n';
        ListNode* prev = new ListNode();
        prev->next = head;
        ListNode* nxt = nullptr;
        temp = prev;
        int i = 0;
        while (i < len - n)
        {
            temp = temp->next;
            i+=1;
        }
        nxt = temp->next->next;
        temp->next = nxt;
        return prev->next;
    }
};
