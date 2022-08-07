class Solution {
public:
    int mod = 1e9+7;
    long long int solve(int i ,int count,int n, vector<vector<long long int>>&arr){
        if(count == n){
            return 1;
        }
        if(arr[i][count] !=-1){
            return arr[i][count]%mod;
        }
        int cnt = 0;
        if(i == 0){
            cnt+=solve(1, count+1, n, arr)%mod;
        }
        if(i == 1){
            cnt+=(solve(0, count+1, n, arr)%mod+ solve(2, count+1, n, arr)%mod)%mod;
        }
        if(i == 2){
            cnt+=(solve(0, count+1, n, arr)%mod+
                solve(1, count+1, n, arr)%mod+
                solve(3, count+1, n, arr)%mod+
                solve(4, count+1, n, arr)%mod)%mod;
        }
        if(i == 3){
            cnt+=(solve(2, count+1, n, arr)%mod+
                solve(4, count+1, n, arr)%mod)%mod;
        }
        if(i == 4){
            cnt+=solve(0, count+1, n, arr)%mod;
        }
        return arr[i][count] = cnt%mod;
        
    }
    int countVowelPermutation(int n) {
        vector<vector<long long int>>arr(5, vector<long long int>(n+1, -1));
        long long int ans = (solve(0, 1, n,arr)%mod+ solve(1, 1, n, arr)%mod+
            solve(2, 1, n,arr)%mod+solve(3, 1, n,arr)%mod+solve(4, 1, n,arr)%mod)%mod;
        return (int)ans;
    }
};