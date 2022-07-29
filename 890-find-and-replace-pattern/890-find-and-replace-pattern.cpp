class Solution {
public:
    vector<string>ans;
    bool check(string s, string pattern){
        unordered_map<char, char>map;
        unordered_map<char, char>map2;
        if(s.size()!=pattern.size()) return false;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(map.find(pattern[i])==map.end() && map2.find(s[i]) == map2.end()){
                map[pattern[i]] = s[i];
                map2[s[i]] = pattern[i];
            }
            if(map[pattern[i]]!=s[i] && map2[s[i]] != pattern[i]) return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        for(int i = 0; i<n; i++){
            if(check(words[i], pattern)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};