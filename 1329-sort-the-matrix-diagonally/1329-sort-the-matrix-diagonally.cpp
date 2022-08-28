class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>>map;
        unordered_map<int, int>index;
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i<n; i++){
              for(int j = 0; j<m; j++){
                  map[i-j].push_back(mat[i][j]);
                  index[i-j] = 0;
              }
        }
        for(auto i:index){
            sort(map[i.first].begin(), map[i.first].end());
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mat[i][j] = map[i-j][index[i-j]];
                // cout<<mat[i][j]<<" ";
                index[i-j]++;
            }
            // cout<<endl;
        }
        return mat;
    }
};