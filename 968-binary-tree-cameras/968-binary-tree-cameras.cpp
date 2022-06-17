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
    //0 covered 
    //1 has cover
    //2 please cover
    int count = 0;
    int postorder(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = postorder(root->left);
        int right = postorder(root->right);
        if(left == 2 || right == 2){
            count++;
            return 1;
        }
        else if(left  == 1 || right == 1){
            return 0;
        }
        else return 2;
        
    }
    int minCameraCover(TreeNode* root) {
        int ans = postorder(root);
        cout<<ans<<endl;
        if(ans == 2) return count+1;
        return count;
    }
};