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
        vector<pair<Node*,Node*>> copied;
        Node* ans = new Node(-1);
        Node* temp = ans;
        unordered_map<Node*,int> mp;
        unordered_map<Node*,Node*> n2n; 
        while (head)
        {
            Node* cur = new Node(head->val);
            mp[cur] = copied.size(); // new list -> new index
            n2n[head] = cur; // original -> new list
            copied.push_back({cur,head->random});
            temp->next = cur;
            temp = temp->next; 
            head = head->next;
        }
        // mp[nullptr] = copied.size();
        for (int i = 0; i < copied.size(); ++i)
        {
            //goal: find the index of random pointer in new list
            auto [node, rnd] = copied[i];
            //rnd
            if (rnd == nullptr)
            {
                copied[i].first->random = nullptr;
            }
            else
            {
                copied[i].first->random = copied[mp[n2n[rnd]]].first;
            }
            // next 
            if (i == copied.size() - 1)
            {
                node->next = nullptr;
                cout << node->val;
            }
            else
            {
                node->next = copied[i+1].first;
            }
        }

        return ans->next;
    }
};
