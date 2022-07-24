class Solution {
public:
    int n;
    int palin[2001][2001];
    bool ispalindrome(int i, int j, string &s)
    {
        if(i>j)
            return true;

        if(palin[i][j]!=-1)
            return palin[i][j];

        if(s[i]!=s[j])
            return palin[i][j]=false;

        return palin[i][j]=ispalindrome(i+1,j-1,s);
    }
    bool solve(int ind, int target,string &s ,vector<vector<int>>&dp){
        //cout<<ind<<" "<<target<<endl;
        if(ind == n){
            if(target == 0){
                return true;
            }
            return false;
        }
        if(target == 0){
            return dp[ind][target] = false;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        bool ans = false;
        for(int i = ind; i<n; i++){
            if(ispalindrome(ind, i, s) && target>0){
                bool temp = solve(i+1, target-1, s, dp);
                if(temp == true)return dp[ind][target] =  true;
            }
        }
        return dp[ind][target] = ans;
    }
    bool checkPartitioning(string s) {
        n = s.size();
        memset(palin,-1,sizeof(palin));
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(0, 3, s, dp);
    }
};