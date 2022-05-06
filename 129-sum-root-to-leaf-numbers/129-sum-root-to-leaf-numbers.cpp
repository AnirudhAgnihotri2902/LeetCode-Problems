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
    vector<string>ans;
    void solution( TreeNode* root, string s){
        if(root == NULL){
            return;
        }
        s+=to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(s);
        }
        solution(root->right, s);
        solution(root->left, s);
        
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        solution(root, s);
        int res = 0;
        for(int i = 0; i<ans.size();i++){
            res+=stoi(ans[i]);
        }
        return res;
    }
};