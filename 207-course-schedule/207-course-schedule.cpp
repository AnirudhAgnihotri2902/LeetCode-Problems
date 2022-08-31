class Solution {
public:
    void dfs(int node, vector<vector<int>> &graph, vector<int> &visited, bool &cycle) {
        cout<<node<<endl;
        if (visited[node] == 1){
            cycle = true; 
            return;
        } 
        if(visited[node] == 2){
            return;
        } 
        visited[node] = 1; 
        for (int i = 0; i < graph[node].size(); i++) {
            dfs(graph[node][i], graph, visited, cycle);
            if (cycle) return; 
        }
        visited[node] = 2; 
    }
    bool canFinish(int numCourses, vector<vector<int>>& prer) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0); 
        for (int i = 0; i < prer.size(); i++) {
            graph[prer[i][1]].push_back(prer[i][0]);
        }
        bool cycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (cycle) return false;
            if (visited[i] == 0) dfs(i, graph, visited, cycle);
        }
        return !cycle;
    }
};