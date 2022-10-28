class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>mp;
        vector<vector<string>>ans;
        int sum =0;
        int index = 0;
        for(int i = 0; i<strs.size();i++){
            string strsum = strs[i];
            sort(strsum.begin(),strsum.end());
            if(mp.find(strsum)== mp.end()){
                vector<string>temp;
                temp.push_back(strs[i]);
                mp.insert({strsum,index});
                index++;
                ans.push_back(temp);
            }
            else{
                ans[mp[strsum]].push_back(strs[i]);
            }
        }
        return ans;
    }
};