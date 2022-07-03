class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(int node, vector<int>arr, vector<vector<int>>&graph){
        if(node == n-1){
            arr.push_back(node);
            ans.push_back(arr);
            return;
        }
        arr.push_back(node);
        for(int i = 0; i<graph[node].size(); i++){
            solve(graph[node][i],arr,graph);    
        }
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int>arr;
        solve(0,arr,graph);
        return ans;
    }
};