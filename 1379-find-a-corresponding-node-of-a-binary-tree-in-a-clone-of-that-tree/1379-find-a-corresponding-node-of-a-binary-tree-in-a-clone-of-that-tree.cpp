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
    TreeNode* ans;
    bool flag = false;
    void inorder(TreeNode* &root, TreeNode* &target){
        if(root == NULL || flag == true){
            return;
        }
        inorder(root->left,target);
        if(root->val == target->val){
            ans = root;
            flag = true;
            return;
        }
        inorder(root->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inorder(cloned,target);
        return ans;
    }
};