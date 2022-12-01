class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char>arr={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        unordered_set<char>set(arr.begin(), arr.end());
        int a=0, b=0;
        for(int i=0; i<s.size(); i++){
            if(set.find(s[i])!=set.end()){
                if(i<(s.size()/2))a++;
                else b++;
            }
        }
        return a==b;
        
    }
};