class Solution {
public:
    string breakPalindrome(string str) {
        if(str.size()==1)return "";
        int n= str.size();
        int odd = -1;
        if(n%2==1)odd = n/2;
        for(int i = 0; i<str.size(); i++){
            if(str[i]!='a'&& i!=odd){
                str[i] = 'a';
                return str;
            }
        }
        str[str.size()-1] = 'b';
        return str;
    }
};