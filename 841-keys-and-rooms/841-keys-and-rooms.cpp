class Solution {
public:
    unordered_set<int>set;
    vector<int>vis;
    void solve(vector<vector<int>>rooms, int i){
        vis[i] = 1;
        set.insert(i);
        for(auto it: rooms[i]){
            if(vis[it] == 0){
                solve(rooms,it);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set.insert(0);
        for(int i = 0; i<rooms.size();i++){
            vis.push_back(0);
        }
        for(int i = 0; i<rooms.size();i++){
            
            if(set.find(i) == set.end()){
                return false;
            }
            if(vis[i] == 0){
                solve(rooms,i);
            }
        }
        return true;
    }
};