class Solution {
public:
    int lcs(string &word1, string& word2, vector<vector<int>>& dp, int i, int j){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(word1[i] == word2[j] ){
            ans = 1+ lcs(word1, word2, dp, i-1, j-1);
        }
        else{
            ans = max(lcs(word1, word2, dp, i-1,j),lcs(word1, word2, dp, i,j-1));
        }
        return dp[i][j] = ans;
    }
    
    
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        int length = lcs(word1, word2,dp, n-1,m-1);
        return (n+m-length-length);
    }
};