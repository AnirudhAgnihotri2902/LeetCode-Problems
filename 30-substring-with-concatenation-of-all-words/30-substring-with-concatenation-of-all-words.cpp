class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.length(),word=words[0].length();
        int m = word*words.size();
        unordered_map<string , int>map;
        for(int i = 0; i<words.size(); i++){
            map[words[i]]++;
        }
        vector<int>res;
        for(int i = 0; i <= n-m; i++){
            string str = s.substr(i, m);
            unordered_map<string, int> temp;
            for(int j = 0; j < m; j+=word){
                string tempstr = str.substr(j, word);
                temp[tempstr]++;
            }
            if(map==temp) res.push_back(i);
        }
        return res;
    }
};