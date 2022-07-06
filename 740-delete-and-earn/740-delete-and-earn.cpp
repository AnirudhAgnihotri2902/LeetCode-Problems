class Solution {
public:
    int solve(int ind, vector<int>&nums, vector<int>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int currvalue = nums[ind];
        int sum = nums[ind];
        int i = ind+1;
        while(i<nums.size() && nums[ind] == nums[i]){
            sum+=nums[ind];
            i++;
        }
        while(i<nums.size() && nums[i] == nums[ind]+1){
            i++;
        }
        return dp[ind] = max(sum+ solve(i,nums,dp), solve(ind+1, nums, dp));
    }
    
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        sort(nums.begin(), nums.end());
        return solve(0,nums, dp);
    }
};