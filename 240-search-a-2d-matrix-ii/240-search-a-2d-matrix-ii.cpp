class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;
        int m =matrix[0].size();
        int vertical = m-1;
        int horizontal = 0;
        int n = matrix.size();
        while(vertical>=0 && horizontal<n){
            if(matrix[horizontal][vertical] == target){
                return true;
            }
            else if(matrix[horizontal][vertical]>target){
                vertical--;
            }
            else{
                horizontal++;
            }
        }
        return false;
    }
};