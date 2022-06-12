class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum =0;
        int ans = INT_MIN;
        unordered_set<int>set;
        int i =0;
        int j = 0;
        while(j<nums.size()){
            while(set.find(nums[j])!=set.end()){
                set.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            sum+=nums[j];
            set.insert(nums[j]);
            ans = max(sum,ans);
            j++;
        }
        return ans;
    }
};