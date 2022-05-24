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
        if(n == 1){
            return nums[0];
        }
        vector<int>dp(n,-1), temp(n-1,0);
        for(int i = 0; i<n-1;i++){
            temp[i] = nums[i];
        }
        int first = solve(n-2,dp, temp);
        for(int i = 0; i<n-1;i++){
            temp[i] = nums[i+1];
            dp[i] = -1;
        }
        int second = solve(n-2,dp, temp);
        int ans = max(first,second);
        return ans;
    }
};