class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>>adj[n+1];
        for(int i = 0; i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>time(n+1, INT_MAX);
        vector<bool>visited(n+1,false);
        time[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> queue;
        queue.push({0,k});
        pair<int, int> temp;
        while(!queue.empty()){
            temp = queue.top();
            queue.pop();
            int u = temp.second;
            visited[u] = true;
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i].first;
                int weight = adj[u][i].second;
                if(visited[v]==false && time[v] > time[u] + weight){
                    time[v] = time[u] + weight;
                    queue.push({time[v], v});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<time.size();i++){
            ans = max(ans, time[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};