class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int>arrr(8, 0);
        for(int j = 0; j<8; j++){
            if(j ==  0 || j == 7)arrr[j] = 0;
            else if(cells[j-1] == cells[j+1] )arrr[j] = 1;
        }
        cells = arrr;
        n  = (n-1)%14;
        for(int i = 0; i<n; i++){
            vector<int>arr(8, 0);
            for(int j = 0; j<8; j++){
                if(j ==  0 || j == 7)arr[j] = 0;
                else if((cells[j-1] == 1 && cells[j+1] == 1) || (cells[j-1] == 0 && cells[j+1] == 0))arr[j] = 1;
            }
            cells = arr;
        }
        return cells;
    }
};