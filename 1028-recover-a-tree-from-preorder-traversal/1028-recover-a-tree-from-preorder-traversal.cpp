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
    int i = 0;
    int solve(TreeNode* root, int level, string &str){
        // cout<<level<<endl;
        if(i >= str.size()){
            return 0;
        }
        string temp = "";
        while(i<str.size() && str[i]!='-'){
            temp+=str[i];
            i++;
        }
        int num = stoi(temp);
        // cout<<num<<endl;
        TreeNode* tem = new TreeNode(num);
        root->left = tem;
        int count = 0;
        while(i<str.size() && str[i] == '-'){
            count++;
            i++;
        }
        // cout<<"Count"<<count<<endl;
        if(count<level)return count;
        if(count>level){
            int newlevel = solve(tem, count, str);
            if(newlevel < level){
                return newlevel;
            }
        }
        temp = "";
        num  = 0;
        while(i<str.size() && str[i]!='-'){
            temp+=str[i];
            i++;
        }
        num = stoi(temp);
        TreeNode* temm = new TreeNode(num);
        root->right = temm;
        
        count = 0;
        while(i<str.size() && str[i] == '-'){
            count++;
            i++;
        }
        if(count<level)return count;
        int newlevel = solve(temm, count, str);
        return newlevel;
    }
    TreeNode* recoverFromPreorder(string str) {
        string temp = "";
        while(i<str.size() && str[i]!='-'){
            temp+=str[i];
            i++;
        }
        int num = stoi(temp);
        TreeNode* ans = new TreeNode(num);
        int count = 0;
        while(i<str.size() && str[i] == '-'){
            count++;
            i++;
        }
        
        int a = solve(ans, count, str);
        return ans;
    }
};