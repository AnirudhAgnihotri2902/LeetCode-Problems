class Solution {
public:
    unordered_map<char, vector<char>>map;
    vector<string>ans;
    
    void solve(string &digits, int i, int n, string s){
        if(i == n){
            if(s == ""){
                return;
            }
            ans.push_back(s);
            return;
        }
        for(auto itr: map[digits[i]]){   
            solve(digits, i+1, n,s+itr);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        map['2'] = {'a','b','c'};
        map['3'] = {'d','e','f'};
        map['4'] = {'g','h','i'};
        map['5'] = {'j','k','l'};
        map['6'] = {'m','n','o'};
        map['7'] = {'p','q','r','s'};
        map['8'] = {'t','u','v'};
        map['9'] = {'w','x','y','z'};
        int n = digits.size();
        string s = "";
        solve(digits, 0, n ,s);
        
        return ans;
    }
};