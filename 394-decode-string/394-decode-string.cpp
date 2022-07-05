class Solution {
public:
    stack<int>stack;
    string solve(string s, int &i){
        int num  = 0;
        string word = "";
        while(i<s.size()){
            if(s[i] == '['){
                i++;
                string ss = solve(s, i );
                while(num){
                    word+=ss;
                    num--;
                }
            }
            else if(s[i] == ']'){
                return word;
            }
            else if(s[i] >='0' && s[i]<='9'){
                num =10*num +(s[i]-'0');
            }
            else{
                word+=s[i];
            }
            i++;
        }
        return word;
    }
    string decodeString(string s) {
        int i = 0;
        return solve(s,i);
        
    }
};