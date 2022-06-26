class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int sum = 0; 
        int maxi = INT_MIN;
        for(int i = 0; i<k; i++){
            sum+=cards[i];
        }
        if(k == cards.size()){
            return sum;
        }
        maxi = max(maxi, sum);
        int cc = k-1;
        for(int i = cards.size()-1; i>=cards.size()-k; i--){
            cout<<i<<" "<<cc<<endl;
            sum+=cards[i];
            sum-=cards[cc];
            cc--;
            maxi = max(sum,maxi);
        }
        return maxi;
    }
};