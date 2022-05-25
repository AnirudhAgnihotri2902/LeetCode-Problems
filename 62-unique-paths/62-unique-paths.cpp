class Solution {
public:
    int solve(vector<vector<int>>&dp, int i, int j){
        if(i>=dp.size()|| j>=dp[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==dp.size()-1&& j==dp[0].size()-1 )return 1;
        int first = solve(dp, i+1,j);
        int second = solve(dp, i,j+1);
        return dp[i][j] = first+second;
    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans = solve(dp,0,0);
        return ans;
    }
};