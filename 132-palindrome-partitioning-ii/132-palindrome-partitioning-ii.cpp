class Solution {
public:
    int n;
    bool ispalindrome(int start, int end, string& s){
        while(start<=end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }
    int solve(int ind, string& s, vector<int>&dp){
        if(ind == n) return 0;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int mini = INT_MAX;
        for(int i = ind; i<n; i++){
            if(ispalindrome(ind, i, s)){
                int count  = 1+ solve(i+1,s, dp);
                mini = min(mini, count);
            }
        }
        return dp[ind] = mini;
    }
    int minCut(string s) {
        n = s.size();
        vector<int>dp(n,-1);
        return solve(0, s,dp)-1;
    }
};