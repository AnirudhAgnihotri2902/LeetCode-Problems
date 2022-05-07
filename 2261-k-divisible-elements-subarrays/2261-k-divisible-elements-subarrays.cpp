class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string>set;
        for(int i = 0; i<nums.size();i++){
            string s = "";
            int count = 0;
            for(int j = i; j<nums.size();j++){
                s+=to_string(nums[j]);
                s+=',';
                if(nums[j]%p == 0){
                    count++;
                }
                if(count> k){
                    break;
                }
                set.insert(s);
            }
        }
        return set.size();
    }
};