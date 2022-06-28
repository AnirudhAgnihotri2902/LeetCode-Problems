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
    TreeNode* solve(TreeNode* root, TreeNode* low, TreeNode* high){
        if((root->val)== low->val ){
            return low;
        }
        if(root->val == high->val){
            return high;
        }
        if(root->val>low->val && root->val<high->val){
            return root;
        }
        TreeNode*ans;
        if(root->val>low->val && root->val>high->val){
            ans = solve(root->left, low, high);
        }
        else if(root->val<low->val && root->val<high->val){
            ans = solve(root->right, low, high);
        }
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return root;
        }
        if(p->val>q->val){
            return solve(root, q,p);
        }
        return solve(root, p,q);
        
        return root;
    }
    
};