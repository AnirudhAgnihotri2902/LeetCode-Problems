class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int start  = entrance[0];
        int end = entrance[1];
        queue<vector<int>>queue;
        maze[start][end] = '+';
        queue.push({start, end});
        int moves = 0;
        while(!queue.empty()){
            int size = queue.size();
            for(int itr = 0; itr<size; itr++){
                vector<int>temp = queue.front();
                int i = temp[0];
                int j = temp[1];
                //cout<<i<<" "<<j<<endl;
                queue.pop();
                if((i== 0 || j == 0|| i == maze.size() - 1 || j == maze[0].size() -1)){
                    if(i != start|| j != end)return moves;
                }
                if(i>0 && maze[i-1][j] == '.'){
                    queue.push({i-1, j});
                    maze[i-1][j] = '+';
                }
                if(j>0 && maze[i][j-1] == '.'){
                    queue.push({i, j-1});
                    maze[i][j-1] = '+';
                }
                if(i<maze.size()-1 && maze[i+1][j] == '.'){
                    queue.push({i+1, j});
                    maze[i+1][j] = '+';
                }
                if(j<maze[0].size()-1 && maze[i][j+1] == '.'){
                    queue.push({i, j+1});
                    maze[i][j+1] = '+';
                }
            }
            moves++;
        }
        return -1;
    }
};