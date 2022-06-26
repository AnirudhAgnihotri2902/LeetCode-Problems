class Solution {
public:
    vector<string>ans;
    void solve(int open, int close, string s){
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        if(close>0){
            solve(open,close-1,s+")");
        }
        if(open>0){
            solve(open-1,close+1,s+"(");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(n,0,"");
        return ans;
    }
};