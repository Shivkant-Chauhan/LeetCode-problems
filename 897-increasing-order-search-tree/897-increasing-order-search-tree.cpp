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
    vector<int> v;
    
    void helper(TreeNode* root){
        if(!root)   return ;
        
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);
        
        TreeNode* temp = root;
        root = temp;
        for(int i = 0; i < v.size(); i++){
            temp->val = v[i];
            temp->left = NULL;
            if(i != v.size()-1)
                temp->right = new TreeNode();
            temp = temp->right;
        }
        // temp->right = NULL;
        
        return root;
    }
};







