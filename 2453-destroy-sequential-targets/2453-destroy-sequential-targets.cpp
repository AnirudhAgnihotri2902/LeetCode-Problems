class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int , int>map;
        int maxi = 0;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]%space]++;
            maxi = max(maxi, map[nums[i]%space]);
        }
        int ans = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            if(map[nums[i]%space] == maxi)ans = min(ans, nums[i]);
        }
        return ans;
    }
};