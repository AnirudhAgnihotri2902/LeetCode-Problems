class Solution {
public:
    int n;
    long long int solve(int ind, vector<int>&nums, vector<long long int>&dp){
        if(ind>=n){
            return 1e8;
        }
        if(ind == n-1){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        long long int ans = INT_MAX;
        for(int i = 1; i<=nums[ind]; i++){
            ans = min(ans, solve(ind+i, nums, dp));
        }
        return dp[ind] = 1+ ans;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        vector<long long int>dp(n+1, -1);
        return (int)solve(0, nums, dp);
    }
};