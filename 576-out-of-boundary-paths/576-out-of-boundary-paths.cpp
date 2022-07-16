class Solution {
public:
    long long int solve(int i, int j, int n, int m, int k, vector<vector<vector<int>>>&dp){
        if(i<0 || j<0 || i>=n || j>=m){
            return 1;
        }
        if(k == 0){
            return 0;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        long long int first ,secoend, third,fourth;
        first = solve(i+1, j, n,m, k-1,dp);
        secoend = solve(i-1, j, n,m, k-1,dp);
        third = solve(i, j+1, n,m, k-1,dp);
        fourth = solve(i, j-1, n, m,k-1, dp);
        return dp[i][j][k] = (first+ secoend+ third+ fourth)%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return (int)solve(startRow, startColumn, m,n,maxMove, dp);
    }
};