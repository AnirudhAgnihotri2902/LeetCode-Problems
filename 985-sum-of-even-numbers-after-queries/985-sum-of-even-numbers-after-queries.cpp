class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int>ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                sum+=nums[i];
            }
        }
        for(int i = 0; i<queries.size(); i++){
            int ind = queries[i][1];
            if(nums[queries[i][1]]%2==0){
                int temp = nums[queries[i][1]];
                nums[queries[i][1]]+=queries[i][0];
                if(nums[queries[i][1]]%2 == 0){
                    sum+=queries[i][0];
                }
                else{
                    sum-=temp;
                }
            }
            else{
                int temp = nums[queries[i][1]];
                nums[queries[i][1]]+=queries[i][0];
                if(nums[queries[i][1]]%2 == 0){
                    sum+=nums[queries[i][1]];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};