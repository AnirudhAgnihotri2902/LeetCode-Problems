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
    vector<vector<int>>ans;
    void solution( TreeNode* root, int targetSum, int currsum, vector<int>arr){
        if(root == NULL){
            return;
        }
        arr.push_back(root->val);
        currsum+=root->val;
        if(currsum == targetSum && root->left == NULL && root->right == NULL){
            ans.push_back(arr);
        }
        solution(root->right, targetSum, currsum, arr);
        solution(root->left, targetSum, currsum, arr);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        solution(root, targetSum, 0, arr);
        return ans;
    }
};