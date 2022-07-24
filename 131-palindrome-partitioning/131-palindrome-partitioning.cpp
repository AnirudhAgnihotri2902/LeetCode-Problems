class Solution {
public:
    int n;
    bool ispalindrome(string &s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    void solve(int i, string &s, vector<string>&arr, vector<vector<string>>&res){
        if(i ==n){
            res.push_back(arr);
            return;
        }
        for(int ind = i; ind<n; ind++){
            if(ispalindrome(s, i, ind)){
                arr.push_back(s.substr(i, ind-i+1));
                solve(ind+1, s, arr,res);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>arr;
        n = s.size();
        solve(0,s,arr,res);
        return res;
    }
};