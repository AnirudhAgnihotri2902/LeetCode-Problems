class Solution {
public:
    int solve(int i, int j, string & s, vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(i == j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return 2+ solve(i+1, j-1, s, dp );
        }
        return max(solve(i,j-1, s, dp), solve(i+1, j, s, dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(s[i] == s[n-1-j]){
                    dp[i+1][j+1] = 1+ dp[i][j];
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        
        
        return n-dp[n][n];
        
    }
};