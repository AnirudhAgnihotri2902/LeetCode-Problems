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
    bool solve(TreeNode* root){
        if(root == NULL){
            return false;
        }
        bool a =false, b = false, flag = false;
        a = solve(root->left);
        b = solve(root->right);
        if(!a)root->left = NULL;
        if(!b)root->right = NULL;
        if(root->val ==1)flag =  true;
        return flag || a || b;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool a = solve(root);
        if(!a){
            return NULL;
        }
        return root;
    }
};