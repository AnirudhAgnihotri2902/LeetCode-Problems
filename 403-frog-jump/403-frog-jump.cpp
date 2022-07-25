class Solution {
public:
    unordered_map<int, int>map;
    int n;
    bool solve(int i, int jumps, vector<int>&arr,vector<vector<int>>&dp ){
        //cout<<i<<" "<<jumps<<endl;
        if(i == n-1) return true;
        if(i>=n) return false;
        if(dp[i][jumps]!=-1){
            return dp[i][jumps];
        }
        bool first = false;
        bool second = false;
        bool third = false;
        if(map.find(arr[i] + jumps+1)!=map.end()){
            first = solve(map[arr[i]+ jumps+1], jumps+1, arr,dp);
        }
        if(jumps>1 && map.find(arr[i]+ jumps-1)!=map.end()){
            second = solve(map[arr[i]+jumps-1], jumps-1, arr,dp);
        }
        if(jumps>0 && map.find(arr[i]+jumps)!=map.end()){
            third = solve(map[arr[i]+jumps], jumps, arr,dp);
        }
        return dp[i][jumps] = first||second||third;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        for(int i = 0; i<n ; i++){
            map[stones[i]] = i;
        }
        vector<vector<int>>dp(n+1, vector<int>(10000, -1));
        return solve(0,0,stones, dp);
        
    }
};