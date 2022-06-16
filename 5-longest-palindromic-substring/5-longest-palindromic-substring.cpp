class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        int start = 0; 
        int end = 0;
        int length = 0;
        for(int i = 0; i<s.length(); i++){
            int len1 = expand(s,i,i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if(len>end-start){
                start = i-((len-1)/2);
                end = i+((len)/2);
                length = len;
            }
        }
        return s.substr(start,length);
    }
    int expand(string s, int start, int end){
        if(s == "" || start<0 || end>=s.length()){
            return 0;
        }
        int count = 0;
        while(start>=0 && end<s.size() && s[start] == s[end]){
            count++;
            start--;
            end++;
        }
        return end-start-1;
    }
};