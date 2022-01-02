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
    ListNode* swapPairs(ListNode* head) {
    //     if(head == NULL || head->next == NULL)
    //         return head;
        
//         ListNode *newHead = NULL;
//         ListNode *temp = head;
//         ListNode *temp2 = temp->next;
//         while(temp!=NULL && temp2!=NULL){
//             if(newHead == NULL){
//                 temp->next = temp2->next;
//                 temp2->next = temp;
//                 newHead = temp2;
//             }
//             else{
//                 temp->next = temp2->next;
//                 temp2->next = temp;
//             }
            
//             temp = temp->next;
//         }
        
//         return newHead;
        
        
        //applying recursive approach
        
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        
        int temp=head->val;
       
        
        swapPairs(head->next->next);
        head->val=head->next->val;
        head->next->val=temp;
        
        return head;
    
    }
};