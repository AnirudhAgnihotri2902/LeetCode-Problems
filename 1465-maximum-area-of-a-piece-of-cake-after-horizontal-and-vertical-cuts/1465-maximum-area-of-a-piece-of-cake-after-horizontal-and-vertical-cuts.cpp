class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long int breadth =INT_MIN;
        long long int length = INT_MIN;
        for(int i = 1; i<=n+1; i++){
            //cout<<horizontalCuts[i]<<" ";
            length = max(length, (long long int)(horizontalCuts[i]-horizontalCuts[i-1]));
        }
        //cout<<length<<endl;
        for(int i = 1; i<=m+1; i++){
            breadth = max(breadth, (long long int)(verticalCuts[i]-verticalCuts[i-1]));
        }
        //cout<<" "<<breadth<<endl;
        length %=1000000007;
        breadth %=1000000007;
        long long int ans  = length*breadth %1000000007;
        return ans%1000000007;
    }
};