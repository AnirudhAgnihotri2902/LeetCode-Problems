class Solution {
public:
    unordered_map<int, int>map;
    int n;
    int solve(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
        if(i == n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(map.find(arr[i]+ arr[j]) == map.end()){
            return 0;
        }
        return dp[i][j] = 1+ solve(j,map[arr[i]+ arr[j]], arr, dp);
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int i = 0; i<n; i++){
            map[arr[i]] = i;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(map.find(arr[i]+ arr[j])!=map.end()){
                    int temp = 2+solve(i, j, arr, dp);
                    ans = max(temp, ans);
                }
            }
        }
        if(ans<3)return 0;
        return ans;
    }
};