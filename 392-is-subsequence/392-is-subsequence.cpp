class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            //cout<<s[i]<<" "<<t[j]<<endl;
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else j++;
        }
        if(i == n)return true;
        return false;
    }
};