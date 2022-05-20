class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& ob,int n,int m){
        if(n<0 || m<0) return 0;
        if(ob[n][m]==1) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(n==0 && m==0) return dp[n][m] = 1;
        int c1 = solve(ob,n-1,m);
        int c2 = solve(ob,n,m-1);
        return dp[n][m] = c1+c2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        memset(dp,-1,sizeof(dp));
        int n = ob.size();
        int m = ob[0].size();
        if(ob[n-1][m-1]==1 || ob[0][0]==1) return 0;
        return solve(ob,n-1,m-1);
    }
};