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
    bool helper(TreeNode* root, double mini, double maxi){
        if(!root)   return true;
        
        if(!(root->val>mini && root->val<maxi)) return false;
        bool p1 = helper(root->left, mini, (double)root->val);
        bool p2 = helper(root->right, (double)root->val, maxi);
        return (p1&p2);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, -2147483649, 2147483648);
    }
};