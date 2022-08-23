class Solution {
public:
    int solve(int i,int two, string str, string &s, vector<vector<int>>& dp){
        //cout<<i<<" "<<str<<" "<<s<<endl;
        if(i == s.length()){
            return 1;
        }         
        if(dp[i][two]!=-1){
            return dp[i][two];
        }
        int first = 0, second = 0;
        string dum = "";
        if(stoi(str+s[i])<27 &&stoi(str+s[i])>9){
            second= solve(i+1,0, str+ s[i], s, dp);
        }
        if(s[i]!='0')first= solve(i+1,1,dum+s[i], s, dp);
        // cout<<i<<" "<<first<<" "<<second<<endl;
        return dp[i][two] =  first+second;
    }
    int numDecodings(string s) {
        vector<vector<int>>dp(s.size()+1, vector<int>(2, -1));
        return solve(0, 0,"", s, dp);
    }
};