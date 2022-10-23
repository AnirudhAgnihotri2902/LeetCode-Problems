class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            int val = nums[i];
            for(int j = i; j<nums.size(); j++){
                val = __gcd(val, nums[j]);
                if(val == k)ans++;
            }
        }
        return ans;
    }
};