class Solution {
public:
    int mod = 1e9+7;
    long long int solve(int i, vector<int>& arr, unordered_set<int>& set, unordered_map<int, int>&dp){
        if(dp.find(i)!=dp.end()){
            return dp[i]%mod;
        }
        long long int count = 1;
        for(auto itr: arr){
            if(itr>i){
                break;
            }
            if(i%itr== 0 && set.find(i/itr)!=set.end()){
                count= (count%mod + (solve(i/itr,arr, set, dp)%mod*solve(itr, arr, set, dp))%mod);
            }
        }
        return dp[i] = count%mod;
        
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, int>dp;
        //cout<<n<<endl;
        unordered_set<int>set;
        for(int i:arr)set.insert(i);
        int count = 0;
        for(auto i: arr){
            //cout<<i<<endl;
            count=count%mod+ solve(i, arr, set, dp)%mod;
        }
        return count%mod;
    }
};