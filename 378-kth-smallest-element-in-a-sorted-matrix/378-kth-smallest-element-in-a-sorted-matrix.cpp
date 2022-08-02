class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int maxi = INT_MIN;
        priority_queue<int>queue;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(queue.size()<k){
                    queue.push(matrix[i][j]);
                }
                else if(queue.top()>matrix[i][j]){
                    queue.pop();
                    queue.push(matrix[i][j]);
                }
            }
        }
        return queue.top();
    }
};