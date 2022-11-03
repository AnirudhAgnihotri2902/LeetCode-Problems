class Solution {
public:
    bool check(vector<int>arr, vector<int>temp){
        for(int i = 0; i<53; i++){
            if(arr[i]!=temp[i])return false;
        }
        return true;
    }
    int numSpecialEquivGroups(vector<string>& words) {
        vector<vector<int>>tab;
        for(int i = 0; i<words.size(); i++){
            vector<int>temp(54, 0);
            for(int j = 0; j<words[i].size(); j++){
                if(j%2 == 0)temp[words[i][j]-'a']++;
                else temp[words[i][j]-'a' + 26]++;
            }
            bool flag = false;
            for(int j = 0; j<tab.size(); j++){
                if(check(temp, tab[j])){
                    flag = true;
                    tab[j][53]++;
                    break;
                }
            }
            if(!flag){
                temp[53]++;
                tab.push_back(temp);
            }
        }
        return tab.size();
    }
};