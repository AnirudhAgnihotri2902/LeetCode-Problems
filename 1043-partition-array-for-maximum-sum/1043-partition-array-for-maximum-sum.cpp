class Solution {
public:
    int n;
    int solve(int ind, int k, vector<int>&arr, vector<int>&dp){
        if(ind == n)return 0;
        if(dp[ind]!=-1) return dp[ind];
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        int len = 0;
        for(int i = ind; i<min(ind+k, n); i++){
            len++;
            maxi = max(maxi, arr[i]);
            int temp = (maxi*len) + solve(i+1, k, arr, dp);
            maxAns = max(maxAns, temp);
        }
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int>dp(n,-1);
        return solve(0,k,arr,dp);
    }
};