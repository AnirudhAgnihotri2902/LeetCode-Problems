class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(j<0|| j>=m){
            return 1e9;
        }
        if(i == n-1){
            return matrix[i][j];
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        int first = solve(i+1, j-1, n,m, matrix, dp);
        int second = solve(i+1, j, n,m,matrix, dp);
        int third = solve(i+1, j+1, n,m,matrix, dp);
        return dp[i][j] = matrix[i][j]+  min({first, second, third});
    } 
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            ans = min(ans, solve(0, i, n,n,matrix, dp));
        }
        return ans;
    }
};