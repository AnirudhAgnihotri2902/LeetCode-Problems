class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int>map;
        for(int i = 0; i<sentence.size(); i++){
            map[sentence[i]]++;
        }
        return (map.size() == 26);
    }
};