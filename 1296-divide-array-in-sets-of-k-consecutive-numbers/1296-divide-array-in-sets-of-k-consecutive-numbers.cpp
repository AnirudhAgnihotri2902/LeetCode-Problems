class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto num : nums)
            m[num]++;
        
        for(auto itr : m){
            while(m[itr.first]){
                for(int i = itr.first; i < itr.first + k; ++i){
                    m[i]--;
                    if(m[i] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};