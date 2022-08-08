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
    stack<int> s1, s2;
    void helper(ListNode* head){
        if(!head)   return ;
        
        s1.push(head->val);
        helper(head->next);
        s2.push(head->val);
    }
    bool isPalindrome(ListNode* head) {
        helper(head);
        
        while(s1.size() > 0){
            if(s1.top() != s2.top())    return false;
            s1.pop();
            s2.pop();
        }
        
        return 1;
    }
};