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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>queue;
        if(root  == NULL){
            return ans;
        }
        queue.push(root);
        int value;
        while(!queue.empty()){
            int size = queue.size();
            for(int i = 0; i<size;i++){
                TreeNode* temp = queue.front();
                queue.pop();
                if(temp->left){
                    queue.push(temp->left);
                }
                if(temp->right){
                    queue.push(temp->right);
                }
                value = (temp->val);
            }
            ans.push_back(value);
        }
        return ans;
    }
};