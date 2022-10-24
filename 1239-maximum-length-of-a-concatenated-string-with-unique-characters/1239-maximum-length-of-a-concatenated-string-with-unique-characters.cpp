class Solution {
public:
    int solve(int ind, vector<string>&arr, vector<int>&map ){
        if(ind == arr.size()){
            return 0;
        }
        int take = 0, nottake;
        bool single = true;
        for(int i = 0; i<arr[ind].size(); i++){
            map[arr[ind][i] - 'a']++;
            if(map[arr[ind][i] -'a']>1){
                single = false;
            }
        }
        if(single){
            take = arr[ind].size() + solve(ind+1, arr, map);
        }
        for(int i = 0; i<arr[ind].size(); i++){
            map[arr[ind][i] - 'a']--;
        }
        nottake = solve(ind+1, arr, map);
        return max(take, nottake);
    }
    int maxLength(vector<string>& arr) {
        vector<int>map(26, 0);
        return solve(0, arr, map);
        
    }
};