class Solution {
public:
    vector<vector<int>>ans;
    void solve(int ind, int target, vector<int>&arr,vector<int>&candidates){
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        if(ind == candidates.size()){
            return;
        }
        for(int i = ind; i<candidates.size(); i++){
            if(i >ind && candidates[i] == candidates[i-1] ){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            arr.push_back(candidates[i]);
            solve(i+1, target-candidates[i], arr,candidates);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>arr;
        solve(0,target, arr,candidates);
        return ans;
    }
};