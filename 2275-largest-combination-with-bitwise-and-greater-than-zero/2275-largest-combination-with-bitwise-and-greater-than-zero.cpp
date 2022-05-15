class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>count(33,0);
        for(int i = 0; i<candidates.size();i++){
            int n = candidates[i];
            int cnt  = 0;
            while (n) {
                if((n & 1) == 1){
                    count[cnt]++;
                }
                cnt++;
                n >>= 1;
            }
        }
        int ans = *max_element(count.begin(),count.end());
        return ans;
    }
};