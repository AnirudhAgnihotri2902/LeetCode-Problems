class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>map;
        int prev = 0;
        unordered_set<int>set;
        for(int i = 0; i<arr.size(); i++){
            map[arr[i]]++;
            prev = map[arr[i]];
        }
        for( auto i : map){
            if(set.find(i.second) != set.end())return false;
            set.insert(i.second);
        }
        return true;
        
    }
};