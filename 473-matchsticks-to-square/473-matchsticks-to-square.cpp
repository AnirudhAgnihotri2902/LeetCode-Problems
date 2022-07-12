class Solution {
public:
    int n;
    bool solve(int ind, int target, vector<int>&value, vector<int>& arr){
        if(ind == n){
            if(value[0] == value[1] && value[1] == value[2] && value[2] == value[3]) return true;
            return false;
        }
        for(int i = 0; i<4; i++){
            if(value[i]+ arr[ind]<=target){
                value[i]+=arr[ind];
                if(solve(ind+1, target, value, arr)) return true;
                value[i]-=arr[ind];
            }
        }
        return false;
    }
    
    
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        n = matchsticks.size();
        for(int i = 0; i<n; i++){
            sum+=matchsticks[i];
        }
        //cout<<sum<<endl;
        if(sum%4!=0){
            return false;
        }
        sum /=4;
        //cout<<sum<<endl;
        vector<int>value(4,0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return solve(0,sum, value, matchsticks);
    }
};