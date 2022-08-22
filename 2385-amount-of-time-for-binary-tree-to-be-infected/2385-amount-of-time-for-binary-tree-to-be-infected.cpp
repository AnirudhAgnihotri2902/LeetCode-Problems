class Solution {
public:
    unordered_map<int, vector<int>>map;
    void solve(TreeNode* root){
        if(root == NULL)return;
        if(root->right){
            map[root->val].push_back(root->right->val);
            map[root->right->val].push_back(root->val);
        }
        if(root->left){
            map[root->val].push_back(root->left->val);
            map[root->left->val].push_back(root->val);
        }
        solve(root->left);
        solve(root->right);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        solve(root);
        int time = 0;
        vector<int>vis(100005,0);
        queue<int>queue;
        queue.push(start);
        vis[start]= 1;
        while(!queue.empty()){
            int size = queue.size();
            bool flag = false;
            for(int i = 0; i<size; i++){
                int temp = queue.front();
                queue.pop();
                for(int j = 0; j<map[temp].size(); j++){
                    if(vis[map[temp][j]]!=1){
                        vis[map[temp][j]] = 1;
                        queue.push(map[temp][j]);
                        flag = true;
                    }
                }
            }
            if(flag)time++;
        }
        return time;
    }
};