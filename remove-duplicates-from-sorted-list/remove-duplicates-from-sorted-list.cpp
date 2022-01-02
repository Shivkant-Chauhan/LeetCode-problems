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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *temp = head;
        while(temp->next!=NULL){
            ListNode *temp2 = temp->next;
            if(temp->val == temp2->val){
                temp->next = temp2->next;
                delete temp2;
            }
            else
                temp = temp->next;
        }
        
        return head;
    }
};