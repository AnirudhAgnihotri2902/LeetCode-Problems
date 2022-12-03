class Solution {
public:
    int bestClosingTime(string customer) {
        int N = customer.size();
        vector<int>y(N+1,0), n(N+1,0);
        int sum  = 0, rest = 0;
        for(int i = N-1, j = 0; i >= 0; i--, j++){
            if(customer[i] == 'Y')sum++;
            y[i] = sum;
            if(customer[j] == 'N')rest++;
            n[j+1] = rest;
        }
        int ans = 0;
        int mini = INT_MAX;
        for(int i = 0; i<=N; i++){
            if(y[i] + n[i] < mini){
                ans = i;
                mini = y[i] + n[i];
            }
        }
        return ans;
    }
};