class Solution {
public:
    int solve(vector<int>& coins, int amount, int n,vector<vector<int>>&dp)
    {
        if(amount == 0) return 0;
        if(n < 0 || amount < 0) return INT_MAX-1;
        if(dp[n][amount]!= -1) return dp[n][amount];
        int one = solve(coins,amount,n-1,dp);
        int two = 1+solve(coins,amount-coins[n],n,dp);
        dp[n][amount] = min(one,two);
        return dp[n][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = solve(coins,amount,coins.size()-1,dp);
        if (ans< INT_MAX-1){
            return ans;
        }
        return-1;
    }
};