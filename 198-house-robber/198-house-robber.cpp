class Solution {
public:
    int solve(int idx, vector<int>&dp, vector<int>&nums){
        if(idx == 0){
            dp[0] = nums[0];
            return dp[idx];
        }
        if(idx<0){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take = nums[idx]+solve(idx-2,dp,nums);
        int nontake = 0+solve(idx-1,dp,nums);
        int res = max(take,nontake);
        dp[idx] = res;
        return dp[idx];
        
    }
    
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = solve(n-1,dp, nums);
        return ans;
    }
};