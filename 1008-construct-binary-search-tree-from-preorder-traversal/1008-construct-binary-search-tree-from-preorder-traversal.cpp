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
    TreeNode* helper(vector<int>& preorder, int start, int end){
        if(start > end) return NULL;
        if(start == end){
            TreeNode* root = new TreeNode(preorder[start]);
            return root;
        }
        if(start+1 == end){
            TreeNode* root = new TreeNode(preorder[start]);
            if(preorder[end] > preorder[start]){
                root->left = NULL;
                root->right= new TreeNode(preorder[end]);
            } else{
                root->left = new TreeNode(preorder[end]);
                root->right = NULL;
            }
            return root;
        }
        
        TreeNode* root = new TreeNode(preorder[start]);
        int temp = start;
        for(int i = start+1; i <= end; i++){
            if(preorder[i] > preorder[start]){
                break;
            }
            temp = i;
        }
        root->left = helper(preorder, start+1, temp);
        root->right= helper(preorder, temp+1, end);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};