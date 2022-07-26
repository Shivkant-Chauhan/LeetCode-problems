/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q)
            return root;
        
        TreeNode *a = NULL, *b = NULL;
        if(root->val > p->val && root->val > q->val){
            a = LCA(root->left, p, q);
        } else if(root->val < p->val && root->val < q->val){
            a = LCA(root->right, p, q);
        } else{
            a = LCA(root->left, p, q);
            b = LCA(root->right, p, q);
        }
        
        if(a!=NULL && b!=NULL){
            return root;
        } else if(a!=NULL){
            return a;
        } else if(b!=NULL){
            return b;
        } else{
            return NULL;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }
};