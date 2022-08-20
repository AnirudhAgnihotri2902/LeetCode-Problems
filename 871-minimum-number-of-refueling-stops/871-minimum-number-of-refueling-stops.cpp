class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int steps = 0;
        priority_queue<int>queue;
        int ind= 0;
        int n = stations.size();
        while(startFuel<target){
            
            while(ind<n && startFuel>=stations[ind][0]){
                queue.push(stations[ind][1]);
                ind++;
            }
            if(queue.empty())return -1;
            startFuel+=queue.top();
            //cout<<startFuel<<endl;
            queue.pop();
            steps++;
        }
        return steps;
    }
};