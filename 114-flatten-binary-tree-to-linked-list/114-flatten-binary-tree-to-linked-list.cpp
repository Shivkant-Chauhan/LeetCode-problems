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
    vector<TreeNode*> v;
    void helper(TreeNode* root){
        if(root == NULL)    return ;
        
        v.push_back(root);
        helper(root->left);
        helper(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root)   return ;
        
        helper(root);
        root = v[0];
        for(int i = 1; i < v.size(); i++){
            root->left = NULL;
            root->right = v[i];
            root = root->right;
        }
        root->left = NULL;
        root->right = NULL;
    }
};