class Solution {
public:
    bool solve(vector<vector<char>> &graph, vector<bool>vis, char cur, char &end) {
        vis[cur - 'a'] = true; 
        if (cur == end) { 
            return true;
        }
        bool res = false;
        for (char &child : graph[cur - 'a']) {
            if (vis[child - 'a'] == false) { 
                if(solve(graph, vis, child, end))return true;
            }
        }
        return res;
    }
    bool equationsPossible(vector<string>& equations) {
         vector<vector<char>> graph(26, vector<char>());
        for (string equ : equations) {
            if (equ[1] == '=' && equ[0] != equ[3]) {
                graph[equ[0] - 'a'].push_back(equ[3]);
                graph[equ[3] - 'a'].push_back(equ[0]);
            }
        }
        vector<bool> vis(26, false);
        for (string equ : equations) {
            if ((equ[1] == '!' && solve(graph, vis, equ[0], equ[3])) || (equ[1] == '=' && !solve(graph, vis, equ[0], equ[3]))) {
                return false;
            }
        }
        return true;
    }
};