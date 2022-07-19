class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr){
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int>dp(n,1), hash(n);
        int maxi = 0;
        int last;
        for(int i = 0; i<n ; i++){
            hash[i] = i;
            for(int j = 0; j<i; j++){
                if(arr[i]%arr[j] == 0 && 1+ dp[j]> dp[i]){
                    dp[i] = 1+ dp[j];
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                last = i;
            }
        }
        vector<int>temp;
        temp.push_back(arr[last]);
        while(hash[last]!=last){
            last = hash[last];
            temp.push_back(arr[last]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};