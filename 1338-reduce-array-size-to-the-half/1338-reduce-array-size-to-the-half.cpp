class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int>map(100005, 0);
        for(int i = 0; i<arr.size();  i++){
            map[arr[i]]++;
        }
        sort(map.rbegin(), map.rend());
        int count = 0;
        int n = arr.size();
        int element = 0;
        for(int i = 0; i<map.size(); i++){
            element+=map[i];
            if(element >=n/2){
                return i+1;
            }
        }
        return 1;
        
    }
};