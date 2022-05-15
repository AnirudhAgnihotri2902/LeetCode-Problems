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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>queue;
        if(root == NULL){
            return 0;
        }
        queue.push(root);
        vector<vector<int>>res;
        while(!queue.empty()){
            vector<int>tempp;
            int size = queue.size();
            for(int i = 0; i<size;i++){
                TreeNode* temp = queue.front();
                queue.pop();
                tempp.push_back((temp->val));
                if(temp->left){
                    queue.push(temp->left);
                }
                if(temp->right){
                    queue.push(temp->right);
                }
            }
            res.push_back(tempp);
        }
        int sum = 0;
        for(int i = 0;i<res[res.size()-1].size();i++)
            sum+=res[res.size()-1][i];
        return sum;
    }
};