class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 1e9;;
        sort(nums.begin(),nums.end());
        for(int i= 0; i<n-2 ;i++){
            int low = i+1;
            int high = n-1;
            while(low <high){
                int currsum = nums[i]+nums[low]+nums[high];
                if(currsum == target)return currsum;
                if(abs(target-currsum)<abs(target-ans)){
                    ans = currsum;
                }
                if(currsum<target){
                    low++;
                }
                else if(currsum>target){
                    high--;
                }
            }
        }
        return ans;
    }
};