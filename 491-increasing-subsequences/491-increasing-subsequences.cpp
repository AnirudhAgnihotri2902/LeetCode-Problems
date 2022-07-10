class Solution {
public:
    vector<vector<int>>res;
    int n;
    struct hashFunction 
    {
      size_t operator()(const vector<int> 
                        &myVector) const 
      {
        std::hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector) 
        {
          answer ^= hasher(i) + 0x9e3779b9 + 
                    (answer << 6) + (answer >> 2);
        }
        return answer;
      }
    };
    unordered_set<vector<int>, hashFunction>set;
    void solve(int i, int prev, vector<int>&arr, vector<int>&nums){
        if(i== n){
            if(arr.size()>1 && set.find(arr)== set.end()){
                res.push_back(arr); 
                set.insert(arr);
            }
            return;
        }
        solve(i+1, prev, arr, nums);
        if(prev == -1 || nums[i]>=nums[prev]){ 
            arr.push_back(nums[i]);
            solve(i+1,i,arr,nums);
            arr.pop_back();
        }
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int>arr;
        solve(0,-1, arr,nums);
        return res;
    }
};