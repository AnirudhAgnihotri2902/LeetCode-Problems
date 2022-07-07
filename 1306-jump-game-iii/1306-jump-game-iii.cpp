class Solution {
public:
    int n;
    bool solve(int ind, vector<int>&nums, vector<int>&dp){
        if(ind<0 || ind>n-1 || dp[ind] == 1){
            return false;
        }
        if(nums[ind] == 0){
            return true;
        }
        dp[ind] = 1;
        bool positive = false;
        if(ind+nums[ind]<n)positive = solve(ind+nums[ind], nums, dp);
        bool negative = false;
        if(ind-nums[ind]>=0)negative=solve(ind-nums[ind], nums,dp);
        return positive || negative;
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<int>dp(n+1,-1);
        return solve(start, arr, dp);
    }
};