class Solution {
public:
    bool solve(int i, int j, string &pattern, string &seq, vector<vector<int>>&dp){
        if(i<0 && j<0){
            return true;    
        }
        if(i<0 && j>=0){
            return false;
        }
        if(j<0 && i>=0){
            for(int li = 0; li<=i; li++){
                if(pattern[li]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        if(pattern[i] == seq[j] || pattern[i] == '?'){
            return dp[i][j] = solve(i-1, j-1, pattern , seq, dp);
        }
        if(pattern[i] == '*'){
            return dp[i][j] = solve(i-1, j, pattern , seq, dp) || solve(i, j-1, pattern, seq, dp);
        }
        return dp[i][j]= false;
    }
    bool isMatch(string str, string pattern) {
        int n = str.size();
        int m = pattern.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1, n-1, pattern , str, dp);
    }
};