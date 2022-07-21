class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        int maxi = 1;
        vector<int>dp(n,1), count(n,1);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++ ){
                if(arr[i]>arr[j] && dp[i]<1+dp[j]){
                    dp[i] = 1+ dp[j];
                    count[i] = count[j];
                }
                else if(arr[i]> arr[j] && dp[i] == 1+dp[j]){
                    count[i] +=count[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(dp[i] == maxi){
                ans+=count[i];
            }
        }
        return ans;
    }
};