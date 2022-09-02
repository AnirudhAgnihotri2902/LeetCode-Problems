class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        unordered_map<int , int>map;
        map[0] = 1;
        int sum = 0;
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            int temp = sum%k;
            if(temp<0) temp += k;
            ans+=map[temp];
            map[temp]++;
        }
        return ans;
    }
};