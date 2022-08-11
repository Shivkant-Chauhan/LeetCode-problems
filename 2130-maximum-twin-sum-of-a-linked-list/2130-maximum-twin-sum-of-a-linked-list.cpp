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
    int pairSum(ListNode* head) {
        stack<int> vals;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            vals.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        int ans = INT_MIN;
        while(slow){
            int temp = vals.top() + slow->val;
            ans = max(ans, temp);
            vals.pop();
            slow = slow->next;
        }
        
        return ans;
    }
};