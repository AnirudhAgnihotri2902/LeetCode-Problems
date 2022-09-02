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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        queue<TreeNode*>ans;
        if(root == NULL){
            return res;
        }
        ans.push(root);
        while(!ans.empty()){   
            int size = ans.size();
            double sum = 0;
            for(int i = 0; i<size;i++){
                TreeNode *aux = ans.front();
                ans.pop();
                sum+=aux->val;
                if(aux->left!=NULL){
                    ans.push(aux->left);
                }
                if(aux->right!=NULL){
                    ans.push(aux->right);
                }
            }
            double temp = sum/size;
            res.push_back(temp);
        }
        return res;
    }
};