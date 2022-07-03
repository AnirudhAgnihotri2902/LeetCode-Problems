class Solution {
public:
    int fdp(int i, int prev, int x, vector<vector<vector<int>>> &dp, vector<int>& nums){
        if (i==nums.size()) return 0;
        if (dp[i][prev][x]!=-1) return dp[i][prev][x];
        
        int p=0;
        
        if (x==0){
            if (nums[i]>nums[prev]) p= 1 + fdp(i+1, i, 1, dp, nums);
        }
        else if (x==1){
            if (nums[i]<nums[prev]) p= 1 + fdp(i+1, i, 0, dp, nums);
        }
        return dp[i][prev][x]= max(p, fdp(i+1, prev, x, dp, nums));
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n= nums.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (n, vector<int>(2, -1)));
        return max(fdp(1, 0, 0, dp, nums)+1, fdp(1, 0, 1, dp, nums)+1);
    }
};