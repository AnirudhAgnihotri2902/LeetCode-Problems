class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
          if (a[1] == b[1])return a[0] > b[0];
          return a[1] < b[1];
     }
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        sort(props.begin(), props.end(), comp);
        int n = props.size();
        int maxi = INT_MIN;
        int ans = 0;
        for (int i = props.size() - 1; i >= 0; i--){
            // cout<<props[i][0]<<" "<<props[i][1]<<endl;
           if (props[i][0] < maxi)ans++;
           maxi = max(maxi, props[i][0]);
        }
        return ans;
    }
};