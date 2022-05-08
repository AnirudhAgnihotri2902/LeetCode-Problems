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
    int count = 0;
    unordered_map<TreeNode* , int>map;
    int countnodes(TreeNode* root, int c){
        if(root == NULL){
            return 0;
            
        }
        int countleft = countnodes(root->left,c);
        int countright = countnodes(root->right, c);
        c++;
        map[root] = c+countleft+countright;
        return c+countleft+countright;
    }
    int dfs(TreeNode*root, int sum){
        if(root == NULL){
            return 0;
        }
        int leftSum = dfs(root->left, sum);
        int rightSum = dfs(root->right, sum);
        int avg = (root->val+leftSum+rightSum)/map[root];
        if(avg == root->val){
            count++;
        }
        return root->val+leftSum+rightSum;
    }
    
    
    
    int averageOfSubtree(TreeNode* root) {
        int a = countnodes(root, 0);
        int b = dfs(root, 0);
        return count;
    }
};