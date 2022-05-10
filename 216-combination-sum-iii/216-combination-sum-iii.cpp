class Solution {
public:
    vector<vector<int>>res;
    void solution(int i, int k, int n, vector<int>arr){
        if(n<0){
            return;
        }
        if(arr.size()>k){
            return;
        }
        if( n==0 && arr.size() ==k ){
            res.push_back(arr);
            return;
        }
        if(i>9){
            return;
        }
        
        solution(i+1, k,n,arr);
        arr.push_back(i);
        solution(i+1,k,n-i,arr);
    }
    vector<int>arr;
    vector<vector<int>> combinationSum3(int k, int n) {
        solution(1,k,n,arr);
        return res;
    }
};