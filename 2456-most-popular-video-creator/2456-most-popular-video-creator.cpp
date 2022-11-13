class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        long long int maxi = 0;
        unordered_map<string , pair<int, string>>map1;
        unordered_map<string, long long int>map2;
        vector<vector<string>>ans;
        for(int i = 0; i<ids.size(); i++){
            map2[creators[i]]+=views[i];
            maxi = max(maxi, map2[creators[i]]);
            if(map1.find(creators[i]) == map1.end())map1[creators[i]] = {views[i], ids[i]};
            else{
                if(map1[creators[i]].first < views[i]){
                    map1[creators[i]].first = views[i];
                    map1[creators[i]].second = ids[i];
                }
                else if(map1[creators[i]].first == views[i]){
                    map1[creators[i]].second = min(map1[creators[i]].second, ids[i]);
                }
            }
        }
        for(auto &i: map2){
            if(i.second == maxi)ans.push_back({i.first, map1[i.first].second});
        }
        return ans;
    }
};