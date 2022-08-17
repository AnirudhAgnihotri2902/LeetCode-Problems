class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>queue;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    queue.push({i, j});
                }
            }
        }
        int time = 0;
        while(!queue.empty()){
            int size = queue.size();
            bool flag = false;
            for(int i = 0; i<size; i++){
                pair<int, int>temp = queue.front();
                //cout<<temp.first<<" "<<temp.second<<endl;
                //grid[temp.first][temp.second] = 2;
                queue.pop();
                if(temp.first>0 && grid[temp.first-1][temp.second] == 1){
                    flag = true;
                    queue.push({temp.first-1, temp.second});
                    grid[temp.first-1][temp.second] = 2;
                }
                if(temp.second>0 && grid[temp.first][temp.second-1] == 1){
                    flag = true;
                    queue.push({temp.first, temp.second-1});
                    grid[temp.first][temp.second-1] = 2;
                }
                if(temp.first< grid.size()-1 && grid[temp.first+1][temp.second] == 1){
                    flag = true;
                    queue.push({temp.first+1, temp.second});
                    grid[temp.first+1][temp.second] = 2;
                }
                if(temp.second<grid[0].size()-1 && grid[temp.first][temp.second+1] == 1){
                    flag = true;
                    queue.push({temp.first, temp.second+1});
                    grid[temp.first][temp.second+1] = 2;
                }
            }
            if(flag){
                time++;
            }
        }
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};