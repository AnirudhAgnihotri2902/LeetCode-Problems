class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        unordered_map<char, int>map;
        for(int i = 0; i<n; i++){
            map[secret[i]]++;
        }
        int bulls = 0;
        int cows = 0;
        for(int i = 0; i<n; i++){
            if(secret[i] == guess[i]){
                bulls++;
                map[secret[i]]--;
            }
        }
        for(int i = 0; i<n; i++){
            cout<<guess[i]<<" "<<map[guess[i]]<<"\n";
            if(map[guess[i]]>0 && guess[i]!=secret[i]){
                cows++;
                map[guess[i]]--;    
            }
        }
        string ans = "";
        ans+=to_string(bulls)+'A'+to_string(cows)+ 'B';
        return ans;
    }
};