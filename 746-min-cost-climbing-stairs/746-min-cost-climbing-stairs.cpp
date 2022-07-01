class Solution {
public:
    int solve(int i, vector<int>&cost, vector<int>&dp){
        if(i>cost.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one = solve(i+1,cost,dp);
        int two = solve(i+2,cost,dp);
        return dp[i] = cost[i]+ min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int first = solve(0,cost,dp1);
        int second = solve(1,cost,dp2);
        return min(first,second);
    }
};