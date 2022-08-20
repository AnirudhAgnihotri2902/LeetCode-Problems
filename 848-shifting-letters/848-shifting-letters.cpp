class Solution {
public:
    string shiftingLetters(string s, vector<int>& shift) {
        int n = shift.size();
        long long int count = 0;
        vector<long long int>map(s.size()+1, 0);
        for(int i = 0; i<n; i++){
            map[i+1]-=shift[i]%26;
            map[0]+=shift[i]%26;
        }
        for(int i = 0; i<s.size(); i++){
            count+= map[i];
            long long int k=count%26;
            long long int p=(s[i]-'a'+k+26)%26;
            s[i]=char('a'+p);
        }
        return s;
    }
};