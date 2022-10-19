class Solution {
public:
    static bool my_compare(string &a, string &b){
        if (a.compare(0, b.size(), b) == 0|| b.compare(0, a.size(), a) == 0)
            return a.size() < b.size();
        else
            return a < b;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>map;
        for(int i = 0; i<words.size();i++){
            map[words[i]]++;
        }
        vector<string>ans;
        int maxi = INT_MIN;
        int n  = k;
        while(n--){
            maxi = INT_MIN;
            vector<string>aux;
            for(auto i :map){
                maxi = max(maxi,i.second);
            }
            for(auto i:map){
                if(i.second == maxi){
                    aux.push_back(i.first);
                    cout<<i.first<<" "<<i.second<<endl;
                    map[i.first] = INT_MIN;
                }
            }
            sort(aux.begin(), aux.end(), my_compare);
            for(int i = 0;i<aux.size();i++){
                ans.push_back(aux[i]);
            }
        }
        vector<string>result;
        for(int i = 0; i<k;i++){
            result.push_back(ans[i]);
        }
        return result;
    }
};