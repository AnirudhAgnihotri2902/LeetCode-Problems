class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        int itr = 0;
        while(truckSize && itr<boxTypes.size()){
            int count = min(boxTypes[itr][0], truckSize);
            ans+=(count*boxTypes[itr][1]);
            itr++;
            truckSize-=count;
        }
        return ans;
    }
};