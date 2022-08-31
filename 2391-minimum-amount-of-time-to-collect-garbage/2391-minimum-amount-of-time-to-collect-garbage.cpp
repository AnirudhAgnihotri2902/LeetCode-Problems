class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = travel.size()+1;
        vector<int>presum(n , 0);
        for(int i = 1; i<n; i++){
            presum[i] = presum[i-1]+ travel[i-1];
            // cout<<presum[i]<<endl;
        }
        int gind=0, mind = 0, pind = 0;
        int gcount = 0, pcount = 0 , mcount = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<garbage[i].size(); j++){
                if(garbage[i][j] == 'G'){
                    gind = max(gind, i);
                    gcount++;
                }
                if(garbage[i][j] == 'M'){
                    mind = max(mind, i);
                    mcount++;
                }
                if(garbage[i][j] == 'P'){
                    pind = max(pind, i);
                    pcount++;
                }
            }
        }
        // cout<<endl;
        // cout<<gind<<" "<<mind<<" "<<pind<<endl;
        int ans = presum[gind] + presum[mind]+ presum[pind] + gcount+ mcount+ pcount;
        return ans;
    }
};