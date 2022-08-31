class Solution {
public:
    stack<int>stack;
    bool cycle = false;
    bool dfs(int ind, vector<int>&vis, vector<vector<int>>& graph){
        if(vis[ind] == 1){
            return true;
        }
        if(vis[ind] == 2)return false;
        vis[ind] = 1;
        bool flag = false;
        for(int i = 0; i<graph[ind].size(); i++){
            if(dfs(graph[ind][i], vis, graph)){
                return true;
            }
        }
        vis[ind] = 2;
        stack.push(ind);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>graph(numCourses);
        for(int i = 0; i<pre.size(); i++){
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>vis(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            if(vis[i] == 0 && dfs(i, vis, graph))return{};
        }
        vector<int>ans;
        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        return ans;
    }
};