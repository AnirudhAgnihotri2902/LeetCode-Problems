class Solution {
public:
    int ans = 0;
    vector<vector<int>>aux;
    int count = 0;
    void solve(vector<vector<int>> &grid, int row ,int col){
        if(grid.empty() || row == -1 || row == grid.size() || col == -1
           || col == grid[0].size() || grid[row][col] == 2 || grid[row][col] == 0) 
            return;
        count++;
        grid[row][col] = 2;
        solve(grid, row - 1, col);
        solve(grid, row + 1, col);
        solve(grid, row, col - 1);
        solve(grid, row, col + 1);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i<grid.size();i++){      
            for(int j = 0; j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    solve(grid,i,j);
                    ans = max(count,ans);
                    //cout<<count<<endl;
                    count = 0;
                }
            }
        }
        return ans;
    }
};