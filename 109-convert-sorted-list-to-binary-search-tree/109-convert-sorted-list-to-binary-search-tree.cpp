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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//     TreeNode* helper(vector<int>& nums, int start, int end){
//         if(start > end){
//             return NULL;
//         }
//         if(start == end){
//             TreeNode* root = new TreeNode(nums[start]);
//             return root;
//         }
        
//         int mid = (start+end)/2;
//         TreeNode* root = new TreeNode(nums[mid]);
//         root->left = helper(nums, start, mid-1);
//         root->right= helper(nums, mid+1, end);
        
//         return root;
//     }
    TreeNode* helper(ListNode* head, ListNode* tail){
        if(!head)   return NULL;
        if(head == tail){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        if(head->next == tail){
            TreeNode* root = new TreeNode(tail->val);
            root->left = new TreeNode(head->val);
            
            return root;
        }
        
        ListNode *slow = head, *fast = head, *prev = NULL;
        while(fast!=tail && fast->next!=tail){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = helper(head, prev);
        root->right= helper(slow->next, tail);
        
        return root;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
//         vector<int> nums;
//         ListNode* temp = head;
//         while(temp != NULL){
//             nums.push_back(temp->val);
//             temp = temp->next;
//         }
        
//         return helper(nums, 0, nums.size()-1);
        if(!head)   return NULL;
        
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        
        return helper(head, tail);
    }
};