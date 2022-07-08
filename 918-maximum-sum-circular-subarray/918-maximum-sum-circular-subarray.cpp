class Solution {
public:
    int kadane(vector<int>&nums, int n){
        int res = nums[0];
        int maxi = nums[0];
        for(int i = 1; i<n; i++){
            maxi = max(maxi+ nums[i], nums[i]);
            res = max(res, maxi);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int normalmaxsum = kadane(nums, n);
        if(normalmaxsum <0){
            return normalmaxsum;
        }
        int arrsum = 0;
        for(int i = 0; i<n; i++){
            arrsum+=nums[i];
            nums[i] = -nums[i];
        }
        int anothersum = arrsum+kadane(nums,n);
        return max(normalmaxsum, anothersum);
    }
};