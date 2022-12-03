class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>>arr;
        unordered_map<char, int>map;
        for(int i = 0; i<s.size(); i++){
            map[s[i]]++;
        }
        for( auto &i: map){
            arr.push_back({i.second, i.first});
        }
        string ans = "";
        sort(arr.begin(), arr.end(), greater<pair<int, char>>());
        for(int i = 0; i<arr.size(); i++){
            int size = arr[i].first;
            for(int j = 0; j<size; j++){
                ans+=arr[i].second;
            }
        }
        return ans;
    }
};