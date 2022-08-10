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
    TreeNode* solve(int i, int j, vector<int>&nums){
        if(i>j){
            return NULL;
        }
        if(i == j){
            TreeNode* ans = new TreeNode(nums[i]);
            return ans;
        }
        int mid = (i+j)/2;
        TreeNode*ans = new TreeNode(nums[mid]);
        ans->left = solve(i, mid-1, nums);
        ans->right = solve(mid+1, j, nums);
        return ans;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0, nums.size()-1, nums);
    }
};