class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r =1;
        int maxprofit = 0;
        int profit;
        while (r< prices.size()){
            if (prices[r]>prices[l]){
                profit = prices[r]-prices[l];
                maxprofit = max(profit,maxprofit);
            }
            else{
                l = r;
            }
            r++;
        }
        return maxprofit;}
};