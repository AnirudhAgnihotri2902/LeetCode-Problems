class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>tab(groupSizes.size()+1);
        for(int i =0; i< groupSizes.size(); i++){
            tab[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(int i = 0; i<tab.size(); i++){
            if(tab[i].size() == 0)continue;
            int j = 0;
            vector<int>temp;
            while(j<tab[i].size()){
                temp.push_back(tab[i][j]);
                if(temp.size() == i){
                    ans.push_back(temp);
                    temp = {};
                }
                j++;
            }
        }
        return ans;
    }
};