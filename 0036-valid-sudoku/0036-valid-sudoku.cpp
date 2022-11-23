class Solution {
public:
    bool checkrow(vector<vector<char>> &board , int i ){
        unordered_set<char>set;
        for(int j = 0; j<9;j++){
            if(board[i][j]!='.'){
                if(set.find(board[i][j])!=set.end()){
                    return false;
                }
                set.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkcolumn(vector<vector<char>>&board, int j){
        unordered_set<char>set;
        for(int i = 0; i<9;i++){
            if(board[i][j]!='.'){
                if(set.find(board[i][j])!=set.end()){
                    return false;
                }
                set.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkgrid(vector<vector<char>>&board, int i, int j){
        unordered_set<char>set;
        for(int itr = 0; itr<3; itr++){
            for(int jtr = 0; jtr<3; jtr++){
                cout<<board[itr+i][jtr+j]<<" ";
                if(board[itr+i][jtr+j]!='.'){
                    if(set.find(board[itr+i][jtr+j]) !=set.end()){
                        return false;
                    }
                }
                set.insert(board[itr+i][jtr+j]);
            }
            
            cout<<endl;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            if(checkrow(board, i) == false){
                return false;
            }
        }
        for(int i = 0 ; i<9; i++){
            if(checkcolumn(board, i) == false){
                return false;
            }
        }
        for(int i = 0; i<9;i+=3){
            for(int j = 0; j<9;j+=3){
                if(checkgrid(board ,i,j) == false){
                    return false;
                }
                cout<<"next"<<endl;
            }
        }
        return true;
    }
};