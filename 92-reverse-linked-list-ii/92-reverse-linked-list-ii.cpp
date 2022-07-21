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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = head, *last1 = head;
        bool flag = false;
        if(left == 1){
            flag = 1;
        }
        
        right -= left;
        while(left > 1){
            left--;
            last1 = temp;
            temp = temp->next;
        }

        ListNode *prev = temp, *curr = temp, *nxt = temp->next;
        while(right--){
            curr = nxt;
            nxt = nxt->next;
            curr->next = prev;
            prev = curr;
        }
        
        if(flag){
            head = prev;
            temp->next = nxt;
        } else{
            last1->next = prev;
            temp->next = nxt;
        }
        
        return head;
    }
};