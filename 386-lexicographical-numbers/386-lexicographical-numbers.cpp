class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>arr;
        for(int i = 1; i<=n; i++ ){
            string s = to_string(i);
            arr.push_back(s);
        }
        sort(arr.begin(), arr.end());
        vector<int>ans(n,0);
        for(int i = 0; i<n; i++){
            ans[i] = stoi(arr[i]); 
        }
        return ans;
    }
};