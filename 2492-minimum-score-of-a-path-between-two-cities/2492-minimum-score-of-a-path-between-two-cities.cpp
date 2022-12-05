class Solution {
public:
    int n;
    void solve(int ind, vector<vector<pair<int, int>>>&arr, vector<int>&vis){
        if(vis[ind] == 1)return;
        vis[ind] = 1;
        for(int i = 0; i<arr[ind].size(); i++){
            solve(arr[ind][i].first, arr, vis);
        }
        return;
    }
    
    int minScore(int N, vector<vector<int>>& roads) {
        n = N;
        vector<vector<pair<int, int>>>arr(n+1);
        for(int i = 0; i<roads.size(); i++){
            arr[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            arr[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<int>vis(n+1, 0);
        solve(n, arr, vis);
        int ans = INT_MAX;
        for(int i = 1; i<=n; i++){
            if(vis[i] == 1){
                for(int j = 0; j<arr[i].size();j++){
                    ans = min(ans, arr[i][j].second);
                }
            }
        }
        return ans;
    }
};