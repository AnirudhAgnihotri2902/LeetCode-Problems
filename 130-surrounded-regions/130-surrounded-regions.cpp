class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&board){
        //cout<<i<<" "<<j<<endl;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == 'X' || board[i][j] =='A'){
            return;
        }
        board[i][j] = 'A';
        dfs(i+1, j, board);
        dfs(i, j+1, board);
        dfs(i-1, j, board);
        dfs(i, j-1, board);
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                //cout<<i<<" "<<j<<endl;
                if(i == 0 || j== 0 || i == board.size()-1 | j== board[0].size()-1){
                    if(board[i][j] == 'O'){
                        dfs(i, j, board);
                    }
                }
            }
        }
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};