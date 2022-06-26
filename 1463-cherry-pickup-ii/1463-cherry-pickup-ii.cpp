class Solution {
public:
    int solve(int i , int j1, int j2, int r, int c, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
        if(j1<0 || j2<0 || j1>=c || j2>=c ){
            return -1e8;
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        if(i == r-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+ grid[i][j2];
            }
        }
        int maxi = -1e8;
        for(int dg1 = -1; dg1<=1; dg1++){
            for(int dg2 = -1; dg2<=1; dg2++){
                int value = 0;
                if(j1 == j2){
                    value+=grid[i][j1];
                }
                else{
                    value = grid[i][j1]+ grid[i][j2];
                }
                value+=solve(i+1, j1+dg1, j2+dg2,r,c, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return solve(0,0,c-1,r,c,grid,dp);
    }
};