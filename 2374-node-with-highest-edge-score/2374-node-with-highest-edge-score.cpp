class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long int maxi = INT_MIN;
        vector<long long int>arr(edges.size(),0);
        for(int i = 0; i<edges.size(); i++){
            arr[edges[i]] +=i;
            maxi = max(maxi, arr[edges[i]]);
        }
        for(int i = 0; i<arr.size(); i++){
            if(maxi == arr[i]){
                return i;
            }
        }
        return (int)maxi;
        
        
    }
};