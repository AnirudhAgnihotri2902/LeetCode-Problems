class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>ss;
        stack<char>tt;
        for(int i = 0; i<s.length();i++){
            if(s[i] == '#'){
                if(ss.empty()== false){
                    ss.pop();
                }
            }
            else{
                ss.push(s[i]);
            }
        }
        for(int i = 0; i<t.length();i++){
            if(t[i] == '#'){
                if(tt.empty() == false){
                    tt.pop();
                }
            }
            else{
                tt.push(t[i]);
            }
        }
        return (ss==tt);
        
    }
};