class Solution {
public:
    string makeGood(string s) {
        string ans;
         int flag=1;
        while(flag){
            string str;
            int prev=s.size();
            int i=0;
            for(i=0;i<s.size()-1;i++){
                if(s[i]-'a'==s[i+1]-'A'||s[i]-'A'==s[i+1]-'a')i++;
                else str.push_back(s[i]);
            }
            if(i<s.size())str.push_back(s[i]);
            if(str.size()==prev||str.size()==0){
                ans=str;
                flag=0;
            }
            else s=str;
        }
        return ans;
    }
};