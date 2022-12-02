class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>first(26,0), second(26,0);
        unordered_set<char>set(word1.begin(), word1.end());
        for(int i = 0; i<word1.size(); i++){
            first[word1[i]-'a']++;
        }
        for(int i = 0; i<word2.size(); i++){
            if(set.find(word2[i]) == set.end())return false;
            second[word2[i]-'a']++;
        }
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        return (first == second);
    }
};