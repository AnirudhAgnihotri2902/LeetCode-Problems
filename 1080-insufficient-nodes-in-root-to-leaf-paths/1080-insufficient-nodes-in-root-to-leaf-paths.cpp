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
    bool dfs(TreeNode* root, int sum, int limit){
        if(root == NULL){
            return false;
        }
        sum+=root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum>=limit){
                return true;
            }
            else{
                return false;
            }
        }
        bool leftside = dfs(root->left, sum, limit);
        bool rightside = dfs(root->right, sum, limit);
        if(leftside == false){
            root->left = NULL;
        }
        if(rightside == false){
            root->right = NULL;
        }
        if(leftside == false && rightside == false){
            return false;
        }
        
        
        return true;
        
    }
    
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root == NULL){
            return root;
        }
        
        bool ans = dfs(root, 0, limit);
        if(ans == false){
            return NULL;
        }
        return root;
        
    }
};