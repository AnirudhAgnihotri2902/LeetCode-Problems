class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string ans;
        for(int i = 1; i<=n;i++){
            if(i == 1){
                ans = "1";
            }
            else{
                ans = solve(ans);
            }
        }
        return ans;
    }
    string solve(string s){
        int count = 1;
        char idx = s[0]; 
        string ans = "";
        for(int i = 1; i<s.length();i++){
            if(s[i]== idx){
                count++;
            }
            else{
                ans+=to_string(count);
                ans+=idx;
                count = 1;
                idx = s[i];
            }
        }
        ans+=to_string(count);
        ans+=idx;
        return ans;
    }
    
    
};