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
    int solve(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return 0;
        }
        arr[root->val]++;
        if(root->right == NULL && root->left == NULL){
            
            int flag = 0;
            for(int i = 0; i<10; i++){
                if(arr[i]%2!=0){
                    flag++;
                }
            }
            arr[root->val]--;
            return (flag<=1);
        }
        int right = 0, left = 0;
        right = solve(root->right, arr);
        left = solve(root->left, arr);
        arr[root->val]--;
        return left+ right;
    }
    
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>arr(10,0);
        return solve(root, arr);
    }
};