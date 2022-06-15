class Solution {
public:
    static bool cmp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
    bool isSubsequence(string s, string t) {
        int a=0,b=0;
        bool ans=true;
        if(s.length()>t.length())
            return false;
        while(a<s.length() && b<t.length()){
            if(s[a]!=t[b]){
                b++;
                ans=false;
            }
            else{
                a++;
                b++;
                ans=true;
            }
        }
        if(a!=s.length())
            ans=false;
        return ans;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n(words.size()), res(1);
        vector<int> ans(n,1);
        for(int i = 0; i < n; i++){
            // int tem = 1;
            for(int j = i+1; j < n; j++){
                int s1 = words[i].size(), s2 = words[j].size();
                if(s2-s1 == 1){
                    if(isSubsequence(words[i], words[j])){
                        ans[j] = max(1 + ans[i], ans[j]);
                        // cout<<words[i]<<" "<<words[j]<<"\n";
                    }
                    res = max(res,ans[j]);
                }
            }
        }
        return res;
    }
};