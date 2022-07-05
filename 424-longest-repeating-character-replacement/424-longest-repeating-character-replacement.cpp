class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int>mp;
        int mx = 0, i = 0, j = 0, res = 0;
        
        for (i = 0; i < n; i++) {
            mp[s[i]]++;
            mx = max(mx,mp[s[i]]);
            while (j < n && i-j-mx+1 > k) {
                mp[s[j]]--;
                j++;
            }
            res = max(res, i-j+1);
        }
        
        return res;    
    }
};