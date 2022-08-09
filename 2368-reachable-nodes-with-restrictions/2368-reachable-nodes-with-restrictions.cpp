class Solution {
public:
    int solve(int i, vector<vector<int>>& graph, vector<int>&vis){
        if(vis[i] == 1){
            return 0;
        }
        vis[i] = 1;
        int count = 0;
        for(int itr = 0; itr<graph[i].size(); itr++){
            if(vis[graph[i][itr]] == 0){
            count +=solve(graph[i][itr], graph, vis);
            }
        }
        return count+1;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>graph(n);
        for(int i = 0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n, 0);
        for(auto i: restricted)vis[i] = 1;
        
        return solve(0, graph,vis);   
    }
};