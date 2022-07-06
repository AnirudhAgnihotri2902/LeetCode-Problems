class Solution {
public:
    int solve(int i, int j , vector<vector<int>>&mat, vector<vector<int>>&dp){
        if(i ==mat.size()-1 && j == mat[0].size() -1){
            return min(0,mat[i][j]);
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down= INT_MIN;
        int right = INT_MIN;
        int zero = 0;
        if(i<mat.size()-1){
            down = mat[i][j]+solve(i+1, j, mat, dp);
        }
        if(j<mat[0].size()-1){
            right = mat[i][j]+ solve(i,j+1, mat,dp);
        }
        right = min(zero,right);
        down = min(zero, down);
        return dp[i][j] = max(down,right);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        int ans =solve(0,0,dungeon,dp);
        return abs(ans) +1;
        
    }
};