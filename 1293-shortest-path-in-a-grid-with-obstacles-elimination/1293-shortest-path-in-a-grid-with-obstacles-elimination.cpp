class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(grid.size() == 1 && grid[0].size() == 1)return 0;
        queue<vector<int>>queue;
        queue.push({0,0,k,0});
        grid[0][0] = 2;
        vector<vector<int>>dis(grid.size(), vector<int>(grid[0].size(), -1));
        dis[0][0]= 0;
        vector<int> dr = {0,1,0,-1,0};
        while(!queue.empty()){
            auto it = queue.front();
            queue.pop();
            int x = it[0], y = it[1], kt = it[2], step = it[3];
            if(x  == grid.size()-1 && y == grid[0].size()-1)return step;
            if(grid[x][y] == 1){
                if(!kt)continue;
                kt--;
            }
            for(int i = 0; i<4; i++){
                int xt = x+ dr[i] , yt = y + dr[i+1];
                if(xt>=0 && xt<grid.size() && yt>= 0 && yt<grid[0].size() && dis[xt][yt] < kt){
                    dis[xt][yt] = kt;
                    queue.push({xt, yt, kt, step+1});
                }
            }
        }
        return -1;
    }
};