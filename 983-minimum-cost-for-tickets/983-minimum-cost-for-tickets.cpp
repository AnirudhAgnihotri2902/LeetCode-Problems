class Solution {
public:
    int f(int i, int d, vector<int>& days, vector<int>& costs, vector<vector<int>>& dp){
        if(i >= days.size())
            return 0;
        if(d >days[days.size()-1])
            return 0;
        if(dp[i][d] != -1) return dp[i][d];
        if(days[i] <= d) return dp[i][d] = f(i+1, d, days, costs, dp);
        int one = costs[0] + f(i+1, days[i]+0, days, costs, dp);
        int seven = costs[1] + f(i+1, days[i]+6, days, costs, dp);
        int thirty = costs[2] + f(i+1, days[i]+29, days, costs, dp);
        return dp[i][d] = min({one, seven, thirty});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n+1, vector<int>(days[n-1]+1,-1));
        return f(0, 0, days, costs, dp);
    }
};