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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        queue<TreeNode*>queue;
        int level = 2;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            if(level == depth){
                for(int i = 0; i<size;i++ ){
                    TreeNode* temp = queue.front();
                    queue.pop();
                    TreeNode* temleft = new TreeNode(val);
                    TreeNode* temright = new TreeNode(val);
                    temleft->left = temp->left;
                    temright->right = temp->right;
                    temp->left = temleft;
                    temp->right = temright;
                }
                return root;
            }
            level++;
            for(int i = 0; i<size; i++){
                TreeNode* temp = queue.front();
                queue.pop();
                if(temp->left){
                    queue.push(temp->left);
                }
                if(temp->right){
                    queue.push(temp->right);
                }
            }
        }
        return root;
    }
};