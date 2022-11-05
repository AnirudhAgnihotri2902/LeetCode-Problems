class Solution {
public:
    bool check(string s1, string s2){
        int count = 0;
        for(int i = 0; i<s1.size(); i++){
            if(s1[i]!=s2[i])count++;
            if(count>2)return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        vector<string>ans;
        for(int i = 0; i<queries.size(); i++){
            string word = queries[i];
            for(int j = 0; j<dict.size(); j++){
                if(check(word, dict[j])){
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};