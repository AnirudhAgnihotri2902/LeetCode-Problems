class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int presum = nums[0]%k;
        unordered_map<int,int> map;
        map[presum] = 0;
        map[0] = -1;
        for(int i = 1;i<n;i++) {
            presum = (presum%k + nums[i]%k) % k;
            if( map.find(presum) != map.end()) {
                if(i - map[presum] > 1)
                return true;
            } else {
                map[presum] = i;
            }
        }
        return false;
    }
};