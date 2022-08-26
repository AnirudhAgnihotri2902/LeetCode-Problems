class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>set;
        set.insert(to_string(1));
        long long int num = 1;
        for(int i = 1; i<=32; i++){
            num*=2;
            string str =to_string(num);
            sort(str.begin(), str.end());
            set.insert(str);
        }
        string str = to_string(n);
        sort(str.begin(), str.end());
        return (set.find(str) != set.end()); 
        return true;
        
    }
};