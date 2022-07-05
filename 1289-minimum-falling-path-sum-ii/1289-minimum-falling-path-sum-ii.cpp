class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i == grid.size()-1){
            return grid[i][j];
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        int mini = 1e9;
        for(int itr = 0; itr<grid.size(); itr++){
            if(itr!=j){
                mini = min(mini, solve(i+1, itr, grid, dp));
            }
        }
        return dp[i][j] = grid[i][j] + mini;
        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            ans = min(ans, solve(0, i, grid, dp));
        }
        return ans;
        
        
    }
};