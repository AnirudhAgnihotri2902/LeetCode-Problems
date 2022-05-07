class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(int i = 0; i<walls.size();i++){
            grid[walls[i][0]][walls[i][1]] = 10;
        }
        for(int i = 0; i<guards.size(); i++){
            grid[guards[i][0]][guards[i][1]] = 20;
        }
        for(int i = 0; i<guards.size();i++){
            for(int j  = guards[i][0]-1; j>=0; j--){
                if(grid[j][guards[i][1]] == 10 || grid[j][guards[i][1]] == 20  ){
                    break;
                }
                grid[j][guards[i][1]] = -1;
            }
            for(int j = guards[i][0]+1; j<m; j++){
                if(grid[j][guards[i][1]] == 10 || grid[j][guards[i][1]] == 20){
                    break;
                }
                grid[j][guards[i][1]] = -1;
            }
            for(int j = guards[i][1]-1; j>=0; j--){
                if(grid[guards[i][0]][j] == 10 || grid[guards[i][0]][j] == 20){
                    break;
                }
                grid[guards[i][0]][j] = -1;
            }
            for(int j = guards[i][1]+1; j<n; j++){
                if(grid[guards[i][0]][j] == 10 || grid[guards[i][0]][j] == 20){
                    break;
                }
                grid[guards[i][0]][j] = -1;
            }
        }
        int count = 0;
        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
        
    }
};