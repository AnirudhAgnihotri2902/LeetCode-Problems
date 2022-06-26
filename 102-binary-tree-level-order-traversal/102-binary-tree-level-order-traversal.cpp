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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>ans;
        if(root == NULL){
            return res;
        }
        ans.push(root);
        while(!ans.empty()){   
            int size = ans.size();
            vector<int>temp;
            for(int i = 0; i<size;i++){
                TreeNode *aux = ans.front();
                ans.pop();
                temp.push_back(aux->val);
                if(aux->left!=NULL){
                    ans.push(aux->left);
                }
                if(aux->right!=NULL){
                    ans.push(aux->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};