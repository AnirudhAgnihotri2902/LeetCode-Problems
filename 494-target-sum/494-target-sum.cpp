class Solution {
public:
    //int dp[21][2009];
    int solve(int ind, int target, vector<int>&nums){
        if(ind ==0){
            if(target == 0 && nums[0] == 0){
                return 2;
            }
            if(target == 0){
                return 1;
            }
            if(target-nums[0] == 0){
                return 1;
            }
            return 0;
        }
        // if(dp[ind][target]!=-1){
        //     return dp[ind][target];
        // }
        int nottake = solve(ind-1, target, nums);
        int take = 0;
        if(target>=nums[ind]){
            take = solve(ind-1, target-nums[ind], nums);
        }
        return take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum =0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }
        if((sum-target)%2 !=0){
            return 0;
        }
        target = (sum-target)/2;
        
        //memset(dp,-1,sizeof(dp));  
        return solve(n-1, target, nums);
        
    }
};