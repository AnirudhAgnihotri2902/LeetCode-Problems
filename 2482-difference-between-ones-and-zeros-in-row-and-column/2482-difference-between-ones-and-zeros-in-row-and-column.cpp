class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>onerow(n, 0), onecol(m,0), zerorow(n,0), zerocol(m,0);
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    zerorow[i]++;
                    zerocol[j]++;
                }
                else{
                    onerow[i]++;
                    onecol[j]++;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                grid[i][j] = onerow[i]+ onecol[j]- zerorow[i] - zerocol[j];
            }
        }
        return grid;
        
    }
};