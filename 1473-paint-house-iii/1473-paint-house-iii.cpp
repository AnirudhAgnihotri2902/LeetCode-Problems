class Solution {
public:
    long long f(int i, int k, int p, vector<int>& houses, vector<vector<int>>& cost, vector<vector<vector<int>>>& dp){
        if(i == houses.size()){
            if (k == 0)
                return 0;
            return INT_MAX;
        }
        if(k < 0)
            return INT_MAX;
        if(dp[i][k][p] != -1) return dp[i][k][p];
        if(houses[i] == 0){
            long long same = INT_MAX, notSame = INT_MAX;
            if(p != 0)
                same = cost[i][p-1] + f(i+1, k, p, houses, cost, dp);
            for(int itr = 0; itr < cost[0].size(); itr++){
                if(itr != p-1)
                    notSame = min(notSame, cost[i][itr] + f(i+1, k-1, itr+1, houses, cost, dp));
            }
            return dp[i][k][p] = min(same, notSame);
        }
        else if(houses[i] == p){
            return dp[i][k][p] = f(i+1, k, p, houses, cost, dp);
        }
        else
            return dp[i][k][p] = f(i+1, k-1, houses[i], houses, cost, dp);
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target+1, vector<int>(n+1,-1)));
        long long ans =  f(0, target, 0, houses, cost, dp);
        if(ans >= INT_MAX) return -1;
        return ans;
    }
};