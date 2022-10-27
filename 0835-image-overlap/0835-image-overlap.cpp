class Solution {
public:
    int count(int ind, int jnd, vector<vector<int>>&arr, vector<vector<int>>&img){
        int cnt = 0;
        for(int i = 0; i<img.size()&& ind+i<arr.size(); i++){
            for(int j = 0; j<img.size() && jnd+j<arr.size(); j++){
                if(arr[ind+i][jnd+j] == 1 && img[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>>arr(3*n , vector<int>(3*n, 0));
        for(int i = n; i< 2*n; i++){
            for(int j = n; j< 2*n; j++){
                if(img2[i-n][j-n] == 1)arr[i][j] = 1;
            }
        }
        
        int maxi = 0;
        for(int i = 0; i< 3*n; i++ ){
            for(int j = 0; j<3*n; j++){
                maxi = max(maxi, count(i, j, arr, img1));
            }
        }
        return maxi;
        
    }
};