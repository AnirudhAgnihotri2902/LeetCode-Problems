class Solution {
public:
    int n;
    int solve(int i, int d, vector<int>& arr, vector<int>& dp){
        //cout<<i<<endl;
        if(i<0 || i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi = 0;
        for(int ind = i+1; ind<min(i+d+1, n); ind++){
            //cout<<ind<<" ";
            if(arr[ind]>=arr[i]) break;
            maxi = max(maxi, solve(ind, d, arr, dp));
        }
        //cout<<endl;
        for(int ind = i-1; ind>=max(i-d, 0); ind--){
            //cout<<ind<<" ";
            if(arr[ind]>=arr[i]) break;
            maxi = max(maxi, solve(ind, d, arr, dp));
        }
        //cout<<endl;
        return dp[i] = 1+ maxi;
    }
    
    
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        //cout<<n<<endl;
        int maxi = 0;
        vector<int>dp(n, -1);
        for(int i = 0; i<n ;i++){
            if(dp[i] == -1){
                maxi = max(maxi, solve(i, d, arr, dp));
            }
        }
        return maxi;
    }
};