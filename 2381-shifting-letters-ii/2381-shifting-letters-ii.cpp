class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shift) {
        int n = shift.size();
        int count = 0;
        vector<int>map(s.size()+1, 0);
        for(int i = 0; i<n; i++){
            if(shift[i][2] == 1){
                map[shift[i][0]]++;
                map[shift[i][1]+1]--;
            }
            else{
                map[shift[i][0]]--;
                map[shift[i][1]+1]++;
            }
        }
        for(int i = 0; i<s.size(); i++){
            count+= map[i];
            int k=count%26;
            int p=(s[i]-'a'+k+26)%26;
            s[i]=char('a'+p);
        }
        return s;
    }
};