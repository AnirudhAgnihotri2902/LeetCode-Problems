class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>map;
        for(int i = 0; i<nums1.size();i++){
            map[nums1[i]]++;
        }
        unordered_set<int>set;
        for(int i = 0; i<nums2.size();i++){
            if(map.find(nums2[i]) != map.end()){
                set.insert(nums2[i]);
            }
        }
        vector<int>ans;
        for(auto it: set){
            ans.push_back(it);
        }
        return ans;
    }
};