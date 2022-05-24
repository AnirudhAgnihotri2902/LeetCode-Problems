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
    unordered_map<TreeNode* , int>map;
    int solve(TreeNode* &root){
        if(root == NULL){
            return 0;
        }
        if(map[root]!=-1){
            return map[root];
        }
        
        int first = root->val;
        if(root->left){
            first +=solve(root->left->right)+ solve(root->left->left);
        }
        if(root ->right){
           first  +=(solve(root->right->left)+ solve(root->right->right));
        }
        //first +=max(secondary, third);
        int second = 0+solve(root->right)+ solve(root->left);
        return  map[root] = max(first,second);
        
    }
    void inorder(TreeNode* &root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        map[root] = -1;
        inorder(root->right);
        
    }
    int rob(TreeNode* root) {
        inorder(root);
        int ans  = solve(root);
        return ans;
    }
};