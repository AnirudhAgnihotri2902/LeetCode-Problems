class Solution {
public:
    long long int solve(int i, int end, int k, vector<vector<vector<int>>>& graph, vector<vector<long  long int>>&dp){
        if(i == end){
            return 0;
        }
        if(k<0){
            return INT_MAX;
        }
        if(dp[i][k]!= -1){
            return dp[i][k];
        }
        long long int ans = INT_MAX;
        for(int ind = 0; ind<graph[i].size(); ind++){
            ans = min(ans, graph[i][ind][1]+ solve(graph[i][ind][0], end, k-1, graph, dp ));
        }
        return dp[i][k] = ans; 
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>>graph(n);
        for(int i = 0; i<flights.size(); i++){
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<vector<long long int>>dp(n+1, vector<long long int>(k+2, -1));
        long long int ans =  solve(src, dst, k, graph, dp);
        if(ans>=INT_MAX){
            return -1;
        }
        return ans;
        
    }
};