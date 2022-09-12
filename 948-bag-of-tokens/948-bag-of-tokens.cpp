class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low = 0;
        int high = tokens.size()-1;
        int res = 0;
        int cnt = 0;
        while(low<=high){
            if(tokens[low]<=power){
                cnt++;
                power-=tokens[low];
                low++;
            }
            else if(cnt>0){
                power+=tokens[high];
                high--;
                cnt--;
            }
            else break;
            res = max(cnt, res);
        }
        return res;
    }
};