class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>arr = nums;
        sort(arr.begin(), arr.end());
        int temp = 0;
        int tempp = 0;
        for(int i = 0; i<nums.size();i++){
            if(nums[i]!=arr[i]){
                temp = i;
                break;
            }
        }
        for(int i = nums.size()-1; i>=0;i--){
            if(nums[i]!=arr[i]){
                tempp = i+1;
                break;
            }
        }
        return tempp-temp;
    }
};