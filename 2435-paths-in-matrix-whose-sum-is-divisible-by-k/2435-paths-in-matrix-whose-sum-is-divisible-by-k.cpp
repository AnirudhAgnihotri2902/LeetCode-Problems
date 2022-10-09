class Solution {
public:
    int n, m;
    int mod = 1e9+7;
    int K;
    long long int solve(int i, int j, int val, vector<vector<int>>&grid, vector<vector<vector<long long int>>>&dp){
        n = grid.size();
        m = grid[0].size();
        // cout<<i<<" "<<j<<" "<<n<<" "<<m<<" ";
        if(i<0 || j<0 || i >= n || j >= m){
            return 0;
        }
        val+=grid[i][j];
        val = val%K;
        // cout<<val<<endl;
        if(i == n-1 && j == m-1){
            return (val== 0);
        }
        if(dp[i][j][val]!=-1){
            return dp[i][j][val];
        }
        long long int first = solve(i+1, j, val, grid, dp)%mod;
        long long int second = solve(i, j+1, val, grid, dp)%mod;
        return dp[i][j][val] = (first+second)%mod;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        K = k;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                grid[i][j] = grid[i][j]%k;
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        vector<vector<vector<long long int>>>dp(n,vector<vector<long long int>>(m,vector<long long int>(k, -1)));
        return (int)(solve(0, 0, 0, grid, dp))%mod;
        
    }
};