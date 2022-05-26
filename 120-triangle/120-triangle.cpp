class Solution {
public:
    int solve(vector<vector<int>>&triangle, vector<vector<int>>& dp, int i, int j, int sum){
        if(i == triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        int first = INT_MAX, second = INT_MAX;
        first = triangle[i][j]+solve(triangle, dp, i+1,j,sum);
        second =triangle[i][j]+solve(triangle, dp, i+1,j+1,sum);
        return dp[i][j] = min(first,second);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(triangle, dp, 0,0,0);
    }
};