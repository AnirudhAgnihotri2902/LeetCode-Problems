class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        for(int i = 0; i<grid.size(); i++){
            int sum = 0;
            for(int j = 0; j<grid[0].size(); j++){
                sum+=grid[i][j];
                grid[i][j] = sum;
                // cout<<grid[i][j]<<" ";
            }
            // cout<<"\n";
        }
        int ans = INT_MIN;
        for(int i = 0; i<grid.size()-2; i++){
            for(int j = 0;j<grid[0].size() -2; j++){
                int temp = 0;
                if(j == 0){
                    temp = grid[i][j+2] + grid[i+1][j+1]-grid[i+1][j] + grid[i+2][j+2];
                }
                else{
                    temp = grid[i][j+2] - grid[i][j-1] + grid[i+1][j+1] -grid[i+1][j] + grid[i+2][j+2] - grid[i+2][j-1];
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};