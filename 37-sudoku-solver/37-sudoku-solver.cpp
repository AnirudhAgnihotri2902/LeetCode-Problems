class Solution {
public:
    bool check(char c,int i, int j, vector<vector<char>>&board){
        char temp = c;
        for(int itr = 0; itr<9; itr++){
            if(itr!=j && board[i][itr] ==temp ){
                return false;
            }
        }
        for(int itr = 0; itr<9; itr++){
            if(itr!=i && board[itr][j] ==temp ){
                return false;
            }
        }
        int itr = (i/3)*3;
        int jtr = (j/3)*3;
        for(int itrr = itr; itrr<itr+3; itrr++){
            for(int jtrr = jtr; jtrr<jtr+3; jtrr++){
                if(itrr!= i && jtrr!= j && board[itrr][jtrr] == temp){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char  c = '1' ; c<='9'; c++  ){
                        if(check(c, i, j, board)){
                            board[i][j] = c;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};