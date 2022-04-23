class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>> & matrix, int i , int j){
        int ans = 1;
        if(dp[i][j]){
            return dp[i][j];
        }
        if(i!=0 && matrix[i-1][j]>matrix[i][j]){
            int temp = solve(matrix, i-1,j);
            ans = max(ans,1+temp);
            dp[i][j] = max(ans,dp[i][j]);
        }
        if(i!=matrix.size()-1 && matrix[i+1][j]> matrix[i][j]){
            int temp = solve(matrix,i+1,j);
            ans = max(ans,1+temp);
            dp[i][j] = max(ans,dp[i][j]);
        }
        if(j!=0 && matrix[i][j-1]>matrix[i][j]){
            int temp = solve(matrix,i,j-1);
            ans = max(ans,1+temp);
            dp[i][j] = max(ans,dp[i][j]);
        }
        if(j!=matrix[i].size()-1 && matrix[i][j+1]>matrix[i][j]){
            int temp = solve(matrix,i,j+1);
            ans = max(ans,1+temp);
            dp[i][j] = max(ans,dp[i][j]);
        }
        return dp[i][j];
        
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi = INT_MIN;
        for(int i = 0; i<matrix.size();i++){
            for(int j = 0; j<matrix[0].size();j++){
                int temp = solve(matrix,i,j);
                maxi = max(maxi,temp);
            }
        }
        return maxi+1;
    }
};