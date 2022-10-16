class Solution {
public:
    long long int solve(int ind, int d, vector<int>&jobs, vector<vector<long long int>>&dp){
        if(d == 0 && ind == jobs.size()){
            return 0;
        }
        if(ind == jobs.size() || d == 0 || jobs.size()-ind <d){
            return INT_MAX;
        }
        if(dp[ind][d]!=-1)return dp[ind][d];
        int maxi = INT_MIN;
        long long int ans = INT_MAX;
        for(int i = ind; i<jobs.size(); i++){
            maxi = max(maxi, jobs[i]);
            ans = min(ans, maxi+ solve(i+1, d-1,jobs, dp));
        }
        return dp[ind][d] = ans;
    }
    int minDifficulty(vector<int>& jobs, int d) {
        vector<vector<long long int>>dp(jobs.size() , vector<long long int>(d+1, -1));
        if(d>jobs.size())return -1;
        return (int)(solve(0,d,jobs, dp));
    }
};