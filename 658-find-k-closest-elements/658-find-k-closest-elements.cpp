class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        int end = arr.size()-1;
        int size = arr.size();
        while(size>k){
            int fromstart = abs(arr[start]-x);
            int fromend = abs(arr[end]-x);
            if(fromstart>fromend){
                start++;
            }
            else{
                end--;
            }
            size--;
        }
        vector<int>ans;
        for(start; start<=end; start++){
            ans.push_back(arr[start]);
        }
        return ans;
    }
};