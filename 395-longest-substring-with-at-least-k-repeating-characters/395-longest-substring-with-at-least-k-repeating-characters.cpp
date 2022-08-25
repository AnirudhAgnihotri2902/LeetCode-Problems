class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k == 1)return s.size();
        int ans =0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            unordered_map<int, int>map;
            int lessK = 0;
            for(int j = i; j<n; j++){
                map[s[j]]++;
                if(map[s[j]] == k){
                    lessK--;
                }
                else if(map[s[j]]== 1){
                    lessK++;
                }
                if(lessK == 0){
                   ans  = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};