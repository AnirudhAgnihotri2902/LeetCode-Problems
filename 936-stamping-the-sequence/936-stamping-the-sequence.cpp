class Solution {
public:
    int maxSubstring(string& s, string& t, int ind){
        int ans = 0, m = t.size();
        int i = 0;
        while(i < m){
            if(s[i+ind] == t[i]) ans++;
            else if(s[i+ind] != '#' and s[i+ind] != t[i]) return 0;
            i++;
        }
        return ans;
    }
    void change(string& t, int ind, int m){
        for(int i = ind; i < ind+m; i++)
            t[i] = '#';
    }
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<int> ans;
        if(target[0] != stamp[0] or target[n-1] != stamp[m-1]) return ans;
        string hash(n,'#');
        // cout<<hash;
        for(int i = 0; i < n; i++){
            int maxi = -1, idx = -1;
            for(int j = 0; j <= n-m; j++){
                int res = maxSubstring(target, stamp, j);
                if(res == 0) continue;
                if(res > maxi){
                    maxi = res;
                    idx = j;
                }
                // cout<<maxi<<" "<<idx<<"\n";
            }
            if(idx != -1){
                change(target, idx, m);
                ans.push_back(idx);
            }
            else if(idx == -1 and target != hash){
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};