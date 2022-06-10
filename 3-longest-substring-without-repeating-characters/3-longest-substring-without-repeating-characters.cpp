class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0;
        vector<int>prev(256,-1);
        int i = 0;
        for(int j = 0;j<n;j++){
            i = max(i,prev[s[j]]+1);
            int maxend = j-i+1;
            res = max(res,maxend);
            prev[s[j]] = j;
        }
        return res;
    }
};