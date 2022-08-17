class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>set;
        for(int i = 0; i<words.size(); i++){
            string word = words[i];
            string str = "";
            for(int j = 0;j<word.size(); j++){
                str+=map[word[j]-'a'];
            }
            set.insert(str);
        }
        return set.size();
    }
};