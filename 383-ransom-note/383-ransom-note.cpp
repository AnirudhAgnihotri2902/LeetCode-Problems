class Solution {
public:
    bool canConstruct(string ransomNote, string magazine){
        unordered_map<char, int>ran, mag;
        for(int i = 0; i<ransomNote.size(); i++)ran[ransomNote[i]]++;
        for(auto i: magazine)mag[i]++;
        for(auto i: ran){
            if(mag[i.first]< i.second)return false;
        }
        return true;
    }
};