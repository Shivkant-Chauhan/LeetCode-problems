/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> add;
        while(headA != NULL){
            add.insert(headA);
            headA = headA->next;
        }
        
        while(headB != NULL){
            auto it = add.find(headB);
            if(it != add.end()) return headB;
            add.insert(headB);
            headB = headB->next;
        }
        
        return NULL;
//O(n^2) appraoch        
//         while(headA != NULL){
//             ListNode* temp = headB;
//             while(temp != NULL){
//                 if(headA == temp){
//                     return headA;
//                 }
//                 temp = temp->next;
//             }
            
//             headA = headA->next;
//         }
        
        return NULL;
    }
};