class Solution {
public:
    bool check(vector<int>&a,vector<int>&b){
        for(int i = 0; i<a.size(); i++){
            if(a[i] == b[i] && a[i]!=0){
                return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>arr(n,vector<int>(26,0));
        for(int i  = 0; i<n;i++){
            for(int j = 0; j<words[i].size(); j++){
                arr[i][words[i][j]-'a'] = 1;
            }
        }
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n;j++){
                if(check(arr[i],arr[j])){
                    int len = words[i].length()*words[j].length();
                    maxi = max(maxi, len);
                }
            }
        }
        if(maxi == INT_MIN)return 0;
        return maxi;
    }
};