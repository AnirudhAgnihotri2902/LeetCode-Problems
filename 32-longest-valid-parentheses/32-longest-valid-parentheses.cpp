class Solution {
public:
    vector<int>arr;
    int longestValidParentheses(string s) {
        vector<int>st,en;
        en.push_back(-1);
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push_back(i);
            else{
                if(!st.empty()){
                    st.pop_back();
                    if(i==s.length()-1) st.push_back(i+1);
                }
                else en.push_back(i);
            }
        }
        for(int i:en) st.push_back(i);
        sort(st.begin(),st.end());
        
        for(int i=1;i<st.size();i++){
            ans=max(ans,st[i]-st[i-1]-1);
        }
        return ans;
    }
};