class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&grid){
        if( i <0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == -1 || grid[i][j]== -2){
            return 0;
        }
        if(grid[i][j] == 2){
            for(int i = 0; i<grid.size(); i++){
                for(int j = 0; j<grid[0].size(); j++){
                    if(grid[i][j] ==0){
                        return 0;
                    }
                }
            }
            return 1;
        }
        bool state = false;
        if(grid[i][j] !=-1){
            grid[i][j] = -2;
            state = true;
        }
        int ans = 0;
        ans+=solve(i+1, j, grid);
        ans+=solve(i-1, j, grid);
        ans+=solve(i, j+1, grid);
        ans+=solve(i, j-1, grid);
        if(state){
            grid[i][j] = 0;
        }
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    res = solve(i, j, grid);
                    return res;
                }
            }
        }
        return res;
    }
};