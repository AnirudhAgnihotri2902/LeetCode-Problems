class Solution {
public:
    struct hashFunction 
    {
      size_t operator()(const vector<int> &myVector) const {
        std::hash<int> hasher;
        size_t answer = 0;
        for (int i : myVector) {
          answer ^= hasher(i) + 0x9e3779b9 + (answer << 6) + (answer >> 2);
        }
        return answer;
      }
    };
  
    unordered_set<vector<int>,hashFunction>map;
    void permute(vector<int>&nums, vector<int>ds, vector<int>freq,vector<vector<int>>&ans){
        if(ds.size() == nums.size()){
            if(map.find(ds) == map.end()){
                map.insert(ds);
                ans.push_back(ds);
                return;
            }
            return;
        }
        for(int i = 0; i<nums.size();i++){
            if(freq[i] == 0){
                ds.push_back(nums[i]);
                freq[i] = 1;
                permute(nums,ds,freq,ans);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>ds;
        vector<int>freq;
        vector<vector<int>>ans;
        for(int i = 0; i<nums.size();i++){
            freq.push_back(0);
        }
        permute(nums,ds,freq,ans);
        return ans;
    }
};