class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>graph(n);
        for(int i = 0;i<n ;i++){
            if(manager[i]!=-1){
                graph[manager[i]].push_back(i);
            }
        }
        int time = 0;
        queue<pair<int, int>>queue;
        queue.push({headID, 0});
        
        while(!queue.empty()){
            auto tem = queue.front();
            int currtime = tem.second;
            int temp = tem.first;
            queue.pop();
            int size = queue.size();
            time = max(time, currtime);
            for(int i = 0; i<graph[temp].size(); i++){
                queue.push({graph[temp][i], currtime+ informTime[temp] });
            }
        }
        return time;   
    }
};