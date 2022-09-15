class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        int n = changed.size();
        unordered_map<int, int>map;
        for(int i = 0; i<n; i++){
            map[changed[i]]++;
        }
        vector<int>arr;
        for(int i = n-1; i>=0; i--){
            if(map[changed[i]]>0){
                map[changed[i]]--;
                if(changed[i]%2 == 0 && map[changed[i]/2]>0){
                    // cout<<changed[i]<<" "<<(changed[i]/2)<<endl;
                    map[(changed[i]/2)]--;
                    arr.push_back(changed[i]/2);
                }
                else{
                    return {};
                }
            }
        }
        return arr;
    }
};