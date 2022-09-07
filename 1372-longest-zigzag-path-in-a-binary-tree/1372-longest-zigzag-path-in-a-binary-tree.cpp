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
    int maxi = 0;
    void solve(TreeNode* root,int dir, int step){
        if(root == NULL){
            return ;
        }
        maxi = max(maxi, step);
        if(dir){
            solve(root->right, 0, step+1);
            solve(root->left, 1, 1);
        }
        else{
            solve(root->left, 1, step+1);
            solve(root->right, 0, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root, 1, 0);
        solve(root, 0, 0);
        return maxi;
    }
};