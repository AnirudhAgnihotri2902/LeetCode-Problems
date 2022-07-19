class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>>ans;
        vector<int>arr;
        arr.push_back(1);
        ans.push_back(arr);
        if(num == 1)return ans;
        arr.push_back(1);
        ans.push_back(arr);
        if(num == 2) return ans;
        num-=2;
        int ind = 1;
        while(num--){
            vector<int>temp;
            temp.push_back(1);
            for(int i = 1; i<ans[ind].size(); i++){
                temp.push_back(ans[ind][i]+ ans[ind][i-1]);
            }
            temp.push_back(1);
            ind++;
            ans.push_back(temp);
        }
        return ans;
    }
};