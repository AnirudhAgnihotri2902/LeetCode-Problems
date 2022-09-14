class Solution {
public:
    int partitionString(string s) {
        vector<int>map(26,0);
        int count = 0;
        for(auto i: s ){
            map[i-'a']++;
            if(map[i-'a']>1){
                count++;
                for(int itr = 0; itr<26; itr++)map[itr] = 0;
                map[i-'a']++;
            }
        }
        return count+1;
    }
};