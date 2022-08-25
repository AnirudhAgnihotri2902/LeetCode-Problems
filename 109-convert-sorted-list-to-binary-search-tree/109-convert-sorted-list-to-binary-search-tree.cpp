/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        return solve(0, arr.size()-1, arr);
    }
};