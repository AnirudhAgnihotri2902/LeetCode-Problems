class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>victory;
        unordered_map<int,int>losses;
        for(int i = 0; i<matches.size();i++){
            victory[matches[i][0]]++;
            losses[matches[i][1]]++;
        }
        vector<int>jeet;
        vector<int>haar;
        for(auto i: victory){
            if(losses[i.first] == 0){
                jeet.push_back(i.first);
            }
        }
        for(auto i: losses){
            if(losses[i.first] == 1){
                haar.push_back(i.first);
            }
        }
        sort(jeet.begin(),jeet.end());
        sort(haar.begin(),haar.end());
        vector<vector<int>>res;
        res.push_back(jeet);
        res.push_back(haar);
        return res;
    }
};