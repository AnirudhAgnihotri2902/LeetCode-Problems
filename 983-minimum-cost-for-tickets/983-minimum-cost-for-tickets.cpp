class Solution {
public:
    int solve(int day, vector<int>& days, vector<int>& costs, vector<int>&map, vector<int>&dp){
        if(day>last){
            return 0;
        }
        if(dp[day]!=-1){
            return dp[day];
        }
        if(map[day] == 0){
            return dp[day] =  solve(day+1, days,costs, map,dp);
        }
        int first = costs[0]+ solve(day+1, days,costs, map,dp);
        int second = costs[1] + solve(day+7, days, costs, map, dp);
        int third = costs[2] + solve(day+30, days, costs, map, dp);
        return dp[day] = min({first, second, third});
        
    }
    int last;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        last = days[days.size()-1];
        vector<int>dp(366,-1);
        vector<int>map(last+1,0);
        for(int i = 0; i<days.size(); i++){
            map[days[i]]++;
        }
        return solve(1,days, costs, map, dp);
    }
};