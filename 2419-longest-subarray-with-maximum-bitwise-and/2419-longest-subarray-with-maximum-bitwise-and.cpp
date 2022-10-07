class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int len = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == maxi){
                len++;
                ans = max(ans, len);
            }
            else{
                len = 0;
            }
        }
        return ans;
    }
};