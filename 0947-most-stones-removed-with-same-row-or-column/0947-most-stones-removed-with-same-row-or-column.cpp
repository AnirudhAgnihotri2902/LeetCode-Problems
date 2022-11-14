class Solution {
public:
    set <int> vis;
    int solve(vector<vector<int>>& stones, int x, int y, int idx) {
        vis.insert(idx);
        int ans = 0;
        for(int i=0;i<stones.size();i++) {
            if(stones[i][0] == x && vis.find(i) == vis.end()){
                ans += 1 + solve(stones, x, stones[i][1], i);
            }
        }
        
        for(int i=0;i<stones.size();i++) {
            if(stones[i][1] == y && vis.find(i) == vis.end()){
                ans += 1 + solve(stones, stones[i][0], y, i);
            }
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int ans = 0;
        for(int i=0;i<stones.size();i++) {
            if(vis.find(i) == vis.end()) {
                int x = stones[i][0], y = stones[i][1];
                ans += solve(stones, x, y, i);
            }
        }
        return ans;
    }
};