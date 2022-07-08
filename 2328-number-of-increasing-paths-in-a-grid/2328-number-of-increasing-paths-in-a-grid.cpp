class Solution {
public:
    int n,m;
    int mod = 1000000007;
    long long int solve(int i, int j , vector<vector<int>>&grid, vector<vector<long long int>>&dp){
        
        if(i<0 || j<0 || i>n-1 || j>m-1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long int count  = 0;
        if(i>0 && grid[i-1][j]>grid[i][j]){
            count+=1+solve(i-1, j, grid, dp);
        }
        if(i<n-1 && grid[i+1][j]>grid[i][j]){
            count+= 1+solve(i+1, j, grid, dp);
        }
        if(j>0 && grid[i][j-1]>grid[i][j]){
            count+=1+solve(i, j-1, grid, dp);
        }
        if(j<m-1 && grid[i][j+1]>grid[i][j]){
            count+= 1+solve(i, j+1, grid, dp);
        }
        //cout<<i<<" "<<j<<" "<<count<<endl;
        count%=mod;
        return dp[i][j] = count;
    }
    int countPaths(vector<vector<int>>& grid){
        n = grid.size();
        m = grid[0].size();
        vector<vector<long long int>>dp(n, vector<long long int>(m,-1));
        long long int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans+=1+solve(i, j, grid, dp);
                ans%=mod;
            }
        }
        ans%=mod;
        return (int)ans;
    }
};