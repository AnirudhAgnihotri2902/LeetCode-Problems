class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefixsum  =0;
        for(int i= 0; i<nums.size(); i++){
            prefixsum += nums[i];
        }
        int leftsum =0; 
        int rightsum = prefixsum ;
        for(int i= 0; i<nums.size(); i++){
            rightsum = rightsum - nums[i];
            if(leftsum == rightsum)
                return i;
            
            leftsum += nums[i];
        }
        return -1;
    }
};