class Solution {
public:
    bool dfs(int ind, vector<vector<int>>& graph, vector<int>& vis, vector<int>& safe){
        if(vis[ind] == 1){
            if(safe[ind] == 1){
                return true;
            }
            return false;
        }
        vis[ind] = 1;
        for(int i = 0; i<graph[ind].size(); i++){
            if(dfs(graph[ind][i], graph, vis, safe)){
                continue;
            }
            else{
                safe[ind] = -1;
                return false;
            }
        }
        safe[ind] = 1;
        return true;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>res;
        int n = graph.size();
        vector<int>safe(n, -1), vis(n, -1);
        
        for(int i = 0; i<n; i++){
            if(graph[i].size() == 0){
                safe[i] = 1;
            }
        }
        for(int i = 0; i<n; i++){
            if(vis[i] == -1){
                dfs(i, graph, vis, safe);
            }
        }
        for(int i = 0; i<n; i++){
            if(safe[i] == 1){
                res.push_back(i);
            }
        }
        
        
        return res;
    }
};