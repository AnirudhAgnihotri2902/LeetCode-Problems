class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int sum = nums[0]+ nums[1]+ nums[2];
        if(nums[0]< (nums[1]+ nums[2])){
            return sum;
        }
        for(int i = 1; i<nums.size()-2; i++){
            sum+=nums[i+2];
            sum-=nums[i-1];
            if(nums[i] <(nums[i+1] +nums[i+2])){
                return sum;
            }
        }
        return 0;
    }
};