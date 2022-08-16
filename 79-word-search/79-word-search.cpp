class Solution {
public:
    bool solve(int i, int j, int ind, string str, vector<vector<char>>&board, vector<vector<bool>>&vis){
        //cout<<i<<" "<<j<<" "<<ind<<endl;
        if(ind == str.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||str[ind]!=board[i][j]||vis[i][j] == true){
            return false;
        }
        vis[i][j] = true;
        bool flag = false;
        flag |=solve(i+1, j , ind+1, str, board, vis);
        flag |=solve(i, j+1 , ind+1, str, board, vis);
        flag |=solve(i-1, j , ind+1, str, board, vis);
        flag |=solve(i, j-1, ind+1, str, board, vis);
        
        vis[i][j] = false;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>vis(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(solve(i, j, 0, word, board, vis) == true){
                    return true;
                }
            }
        }
        return false;
    }
};