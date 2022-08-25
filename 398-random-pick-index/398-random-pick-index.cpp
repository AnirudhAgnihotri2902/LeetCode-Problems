class Solution {
public:
    unordered_map<int, vector<int>>map;
    unordered_map<int, long long int>mp;
    
    Solution(vector<int>& nums) {
        for(int i= 0; i<nums.size(); i++){
            map[nums[i]].push_back(i);
            mp[nums[i]]= 0;
        }
    }
    
    int pick(int target) {
        int ans = map[target][mp[target]%map[target].size()];
        mp[target]++;
        return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */