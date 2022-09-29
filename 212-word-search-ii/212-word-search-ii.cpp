struct Node{
    Node *link[26];
    bool flag = false;
    string wrd ;
    
    bool containkey(char ch){
        return (link[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        link[ch-'a'] = node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
    void setend(){
        flag = true;
    }
    void offflag(){
        flag = false;
    }
    void setword(string word){
        wrd = word;
    }
    bool isend(){
        return flag;
    }
    string getword(){
        return wrd;
    }
};


class Solution {
public:
    vector<string>ans;
    void insert(string word, Node* root) {
        Node* node = root;
        for(int i=0; i<word.size(); i++ ){
            if(!node->containkey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setword(word);
        node->setend();
    }
    
//     bool findword(string prefix, Node* root){
//         Node* node = root;
//         for(int i = 0; i<prefix.size(); i++){
//             if(!node->containkey(prefix[i])){
//                 return false;
//             }
//             node = node->get(prefix[i]);
//         }
//         return true;
//     }
    void dfs(Node* node,int i, int j, vector<vector<char>>&board, vector<vector<int>>&vis){
        // cout<<i<<" "<<j<<endl;
        // cout<<endl;
        if(i<0 || i== board.size() || j <0 || j== board[0].size() || vis[i][j] == 1 || !node->containkey(board[i][j])){
            return;
        }
        vis[i][j] = 1;
        
        // for(int itr = 0; itr<vis.size(); itr++){
        //     for(int jtr = 0; jtr<vis[0].size(); jtr++){
        //         cout<<vis[itr][jtr]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        node = node->get(board[i][j]);
        if(node->isend()){
            ans.push_back(node->wrd);
            node->offflag();
        }
        dfs(node, i+1, j, board, vis);
        dfs(node, i, j+1, board, vis);
        dfs(node, i-1, j, board, vis);
        dfs(node, i, j-1, board, vis);
        vis[i][j] = 0;
        return;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        vector<vector<int>>vis(board.size(), vector<int>(board[0].size(), 0));
        for(string word:words){
            insert(word, root);
        }
        for(int i = 0;i<board.size();  i++ ){
            for(int j = 0; j<board[0].size(); j++){
                Node* node = root;
                dfs(node, i, j, board, vis);
            }
        }
        
        return ans;
    }
};