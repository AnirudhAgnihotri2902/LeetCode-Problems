class Solution {
public:
    int solve(vector<int>&nums, vector<vector<int>>&dp,int prev, int i , int number){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][prev+1] !=-1){
            return dp[i][prev+1];
        }
        int first = INT_MIN ,second = INT_MIN;
        first = solve(nums, dp, prev, i+1,number );
        if(prev==-1 || nums[prev]<nums[i])
        second = 1+ solve(nums, dp, i, i+1, number);
        
        return dp[i][prev+1]=max(first,second);
    }
    
    
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        int solution = solve(nums, dp, -1, 0,0);
        return solution;
    }
};