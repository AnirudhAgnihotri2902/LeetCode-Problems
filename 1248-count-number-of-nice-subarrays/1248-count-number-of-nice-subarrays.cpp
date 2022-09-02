class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i = 0; i<n; i++){
            arr[i] = arr[i]%2;
        }
        int ans = 0;
        int sum = 0;
        unordered_map<int, int>map;
        map[sum] = 1;
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            map[sum]++;
            if(map.find(sum-k)!=map.end()){
                ans+=map[sum-k];
            }
        }
        return ans;
    }
};