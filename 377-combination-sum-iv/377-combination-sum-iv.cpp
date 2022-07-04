class Solution {
public:
    int solve(int ind, int target, vector<int>&nums, vector<vector<int>>&dp, vector<int>&arr){
        if(target == 0){
            return 1;
        }
        if(dp[ind][target] !=-1){
            return dp[ind][target];
        }
        //int nottake = solve(ind-1, target, nums, dp );
        int count = 0;
        for(int i = nums.size()-1; i>=0; i--){
            if(target>=nums[i]){
                arr.push_back(nums[i]);
                count+=solve(i, target - nums[i], nums, dp, arr);
                arr.pop_back();
            }
        }
        return dp[ind][target] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        vector<int>arr;
        return solve(n-1, target, nums, dp, arr);
    }
};