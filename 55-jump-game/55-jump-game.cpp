class Solution {
public:
    
    bool solve(vector<int>&nums,vector<int>&dp, int itr){
        if(itr>nums.size()-1){
            return false;
        }
        if(itr == nums.size()-1) return true;
        for(int i = 1; i<=nums[itr];i++){
            if(dp[itr+i] == 0){
                continue;
            }
            if(solve(nums, dp,itr+i) == true){
                return true;
            }
            else{
                dp[itr+i] = 0;
            }
        }
        return false;
    }
    
    
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,dp, 0);
        
    }
};