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
    ListNode* partition(ListNode* head, int x) {
        vector<int> small, gr;
        ListNode* temp = head;
        while(temp){
            if(temp->val < x)   small.push_back(temp->val);
            else                gr.push_back(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        for(auto &i : small){
            temp->val = i;
            temp = temp->next;
        }
        for(auto &i : gr){
            temp->val = i;
            temp = temp->next;
        }
        
        return head;
    }
};