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
    ListNode* revL(ListNode* lst)
    {
        ListNode* prev = lst;
        ListNode* next = nullptr;
        while (lst)
        {
            prev = lst;
            lst = lst->next;
            if (lst->next == nullptr)
                break;
            next = lst->next;
            lst->next = prev;
            lst = next;
        }

        return lst;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;

        // head1 = revL(head1);
        // head2 = revL(head2);
        int carry = 0;
        while (head1 && head2)
        {
            int total = head1->val + head2->val + carry;
            dummy->next = new ListNode(total % 10);
            carry = total >= 10;
            head1 = head1->next;
            head2 = head2->next;
            dummy = dummy->next;
        }
        while (head1)
        {
            int total = head1->val + carry;
            dummy->next = new ListNode(total % 10);
            carry = total >= 10;
            head1 = head1->next;
            dummy = dummy->next;
        }

        while (head2)
        {
            int total = head2->val + carry;
            dummy->next = new ListNode(total % 10);
            carry = total >= 10; 
            head2 = head2->next;
            dummy = dummy->next;
        }
        if (carry)
            dummy->next = new ListNode(1);
        return ans->next;

    }
};
