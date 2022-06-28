class Solution {
public:
    bool solve(int i, int target, vector<int>&nums, vector<vector<int>>&dp ){
        if(i== nums.size()){
            return false;
        }
        if(target == 0){
            return true;
        }
        if(dp[i][target] !=-1){
            return dp[i][target];
        }
        bool take = false;
        bool nottake = false;
        nottake = solve(i+1, target, nums, dp);
        if(target-nums[i]>=0){
            take = solve(i+1, target-nums[i], nums, dp);
        }
        return dp[i][target] = take || nottake;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2 == 1){
            return false;
        }
        sum/=2;
        vector<vector<int>>dp(nums.size(),vector<int>((sum+1), -1));
        return solve(0, sum, nums, dp);
    }
};