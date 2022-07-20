class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int mod = 1000000007;
        long long int zero = 0;
        long long int res = arr[0];
        long long int maxi = arr[0];
        long long int n = arr.size();
        for(int i = 1; i<n; i++){
            maxi = max((long long int)arr[i], arr[i]+maxi);
            res = max(res, maxi);
            res%=mod;
        }
        res = max(res, zero);
        long long int presum = 0;
        long long int sufsum = 0;
        long long int sum = 0;
        maxi = 0;
        for(int i = 0; i<n; i++){
            presum+=arr[i];
            maxi = max(maxi, presum);
            sum+=arr[i];
        }
        presum = maxi;
        sum%=mod;
        sum = max(sum, zero);
        presum%=mod;
        maxi = 0;
        for(int i = n-1; i>=0; i--){
            sufsum+=arr[i];
            maxi = max(maxi, sufsum);
        }
        maxi = max(sufsum, maxi);
        sufsum = maxi;
        sufsum%=mod;
        long long int ans;
        //cout<<presum<<" "<<sufsum<<" "<<sum<<endl;
        if(k == 1){
            return res;
        }
        ans = max(res,(presum+ sufsum+ (sum*(k-2))%mod))%mod;
        return (int)ans;
    }
};