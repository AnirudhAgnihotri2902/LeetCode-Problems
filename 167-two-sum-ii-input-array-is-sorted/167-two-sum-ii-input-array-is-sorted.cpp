class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        vector<int>ans;
        while(start<end){
            if ((nums[start]+nums[end]) == target){
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
            if((nums[start]+nums[end]) < target){
                start++;
            }
            if((nums[start]+nums[end])> target){
                end--;
            }
        }
        return ans;
    }
};