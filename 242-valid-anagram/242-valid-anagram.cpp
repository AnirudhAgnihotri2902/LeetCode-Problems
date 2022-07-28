class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        for(auto i: s)arr1[i-'a']++;
        for(auto i:t)arr2[i-'a']++;
        return arr1==arr2;
    }
};