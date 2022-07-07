class Solution {
public:
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3,vector<vector<vector<int>>>&dp){
        if(i>=n && j>=m && k>=l){
            return true;
        }
        if(k>=l){
            return false;
        }
        if(dp[i][j][k] !=-1){
            return dp[i][j][k];
        }
        bool first = false;
        bool  secoend = false;
        if( s1[i] == s3[k]){
            first = solve(i+1,j,k+1, s1,s2,s3,dp);
        }
        if(s2[j] == s3[k]){
            secoend = solve(i, j+1,k+1,s1,s2,s3,dp);
        }
        return dp[i][j][k] = (first || secoend);
    }
    int n,m,l;
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        l = s3.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(l+1,-1)));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};