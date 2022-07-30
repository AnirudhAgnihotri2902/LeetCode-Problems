class Solution {
public:
    bool check(string &word, vector<int>&map){
        //cout<<word<<endl;
        vector<int>arr(26,0);
        for(int i = 0; i<word.size(); i++){
            arr[word[i]-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(arr[i]<map[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>map(26,0);
        for(int i = 0; i<words2.size(); i++){
            vector<int>temp(26,0);
            for(int j = 0; j<words2[i].size(); j++){
                temp[words2[i][j]-'a']++;
            }
            for(int j = 0; j<26; j++){
                map[j] = max(map[j], temp[j]);
            }
        }
        // for(int i = 0; i<26; i++){
        //     cout<<map[i]<<" ";
        // }
        // cout<<endl;
        for(int i = 0; i<words1.size(); i++){
            if(check(words1[i], map)){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};