class Solution {
public:
	vector<vector<string>> ans;
    bool isSafe(vector<string> &board,int x,int y,int n){
        for(int row =0;row<x;row++){    
            if(board[row][y] == 'Q')
                return false;
        }

        int row = x,col = y;
        while(row>=0 and col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        row = x,col =y;
        while(row>=0 and col<n){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }

    void queen(vector<string>& board,vector<vector<string>>& ans,int x,int n)
    {
        if(x>=n){
            ans.push_back(board);
            return ;
        }
        for(int col = 0;col<n;col++){
            if(isSafe(board,x,col,n)){
                board[x][col] = 'Q';
                queen(board,ans,x+1,n);
                board[x][col] = '.';
            }
        }
        // return false;
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n);
        string s(n,'.');
        for(int i =0;i<n;i++)
        {
            board[i] = s;
        }
        // for(int i =0;i<n;i++){
        //     cout<<board[i]<<endl;
        // }
        queen(board,ans,0,n);
        return ans;
    }
};