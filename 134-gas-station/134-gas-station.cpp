class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int fuel = 0; 
        int paisa = 0;
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            fuel+=gas[i];
            paisa+=cost[i];
            arr[i] = gas[i]-cost[i];
        }
        if(paisa>fuel) return -1;
        int ans = 0;
        int amt = 0;
        for(int i = 0; i<n; i++){
            amt+=arr[i];
            if(amt <0){
                ans = i+1;
                amt = 0;
            }
        }
        return ans;
    }
};