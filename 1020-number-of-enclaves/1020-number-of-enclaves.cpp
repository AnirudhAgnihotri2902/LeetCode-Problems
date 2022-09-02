class Solution {
public:
    void solve(int i, int j, vector<vector<int>>&grid){
        if(i<0 || j<0 || i== grid.size() || j== grid[0].size()|| grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        solve(i+1, j, grid);
        solve(i-1, j, grid);
        solve(i, j+1, grid);
        solve(i, j-1, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        for(int i = 0; i<n; i++ ){
            solve(i, 0, grid);
            solve(i, m-1, grid);
        }
        for(int i = 0; i<m; i++){
            solve(0, i, grid);
            solve(n-1, i, grid);
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};