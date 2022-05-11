class Solution {
public:
    vector<int>dp;
    void fill(){
        vector<int> v={1,1,1,1,1},pr(5);
        for(int i=1;i<=50;i++){
            pr[0]=1;
            for(int j=1;j<5;j++)
                pr[j]=pr[j-1]+v[j];
            dp.push_back(pr[4]);
            v=pr;
        }
        
    }
    int countVowelStrings(int n) {
        fill();
        return dp[n-1];
    }
};