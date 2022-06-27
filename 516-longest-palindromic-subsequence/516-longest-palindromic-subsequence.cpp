class Solution {
public:
    int solve(int i, int j, string &s, vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        int ans = 0;
        if(i == j){
            return 1;
        }
        if(s[i] == s[j]){
            ans = 2+ solve(i+1,j-1,s,dp);
        }
        else{
            ans+=max(solve(i,j-1,s,dp), solve(i+1,j,s,dp));
        }
        return dp[i][j] = ans; 
        
    }
    
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return max(1,solve(0,n-1,s,dp));
    }
};