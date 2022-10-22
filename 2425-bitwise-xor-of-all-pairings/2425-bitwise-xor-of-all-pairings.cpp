class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0; i<n; i++){
            if(m%2 != 0){
                ans^=nums1[i];
            }
        }
        for(int i = 0; i<m; i++){
            if(n%2 != 0){
                ans^=nums2[i];
            }
        }
        return ans;
    }
};