class Solution {
public:
    int mod =1e9+7;
    int end;
    long long int solve(int i,int k, vector<vector<int>>&dp){
        // cout<<i<<" "<<k<<endl;
        if(k == 0){
            return (i == end) ;
        }
        if(dp[i+2001][k]!=-1){
            return dp[i+2001][k];
        }
        long long int ans = 0;
        ans+=solve(i+1, k-1, dp);
        ans+=solve(i-1, k-1, dp);
        return dp[i+2001][k]=ans%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(10000, vector<int>(k+1, -1));
        end = endPos;
        return solve(startPos, k, dp)%mod;
    }
};