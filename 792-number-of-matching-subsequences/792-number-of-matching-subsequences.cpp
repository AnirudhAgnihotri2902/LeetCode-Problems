class Solution {
public:
    bool issubsequence(string str, string s){
        int i = 0, j = 0;
        while(i<str.size()&& j<s.size()){
            if(str[i] == s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i!=str.size()){
            return false;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int>map;
        for(int i = 0; i<words.size(); i++){
            map[words[i]]++;
        }
        int count = 0;
        for(auto temp:map){
            string str = temp.first;
            if(issubsequence(str, s)){
                count+=temp.second;
            }
        }
        return count;
    }
};