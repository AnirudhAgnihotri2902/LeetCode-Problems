class Solution {
public:
    int candy(vector<int>& rating) {
        int n= rating.size();
        vector<int>left(n,1), right(n,1);
        for(int i = 1; i<n; i++){
            if(rating[i]>rating[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        for(int i = n-2; i>=0; i--){
            if(rating[i]>rating[i+1]){
                right[i] = right[i+1]+1;
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans+=max(right[i], left[i]);
        }
        return ans;
    }
};