class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         
        int currsum = 0;
        int maxsum = INT_MIN;
        int n = nums.size();
        for(int i= 0; i<n; i++){
            currsum+=nums[i];
            if (maxsum < currsum){
                maxsum = currsum;
            }
            if (currsum<0){
                currsum = 0;
            }
        }
        return maxsum;
    }
};