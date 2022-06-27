class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
        for(int i = 0; i<n.size(); i++){
            int num = n[i]-'0';
            maxi = max(num, maxi);
        }
        return maxi;
        
    }
};