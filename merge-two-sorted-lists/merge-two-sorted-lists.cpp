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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        
        ListNode *temp1 = list1, *temp2 = list2;
        ListNode *newHead = NULL;
        ListNode *temp = NULL;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val < temp2->val){
                if(newHead == NULL){
                    newHead = temp1;
                    temp = temp1;
                }
                else{
                    temp->next = temp1;
                    temp = temp1;
                }
                temp1 = temp1->next;
            }
            else{
                if(newHead == NULL){
                    newHead = temp2;
                    temp = temp2;
                }
                else{
                    temp->next = temp2;
                    temp = temp2;
                }
                temp2 = temp2->next;
            }
            
        }
        
        while(temp1 != NULL){
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        }
            
        while(temp2 != NULL){
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
        
        
        return newHead;
    }
};