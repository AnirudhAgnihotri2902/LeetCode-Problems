class Solution {
public:
     vector<int>color;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        cout<< n<<endl;
        for(int i = 0; i<graph.size();i++){
            color.push_back(-1);
        }
        for(int i = 0; i<n;i++){
            if(color[i] == -1){
                cout<<i<<endl;
                if(checkBipartite(i,graph,color) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBipartite( int src, vector<vector<int>>&graph , vector<int> &color){
        queue<int>queue;
        queue.push(src);
        color[src] = 1;
        while(!queue.empty()){
            int node = queue.front();
            queue.pop();
            for(auto it:graph[node]){
                if(color[it] == -1){
                    color[it] = 1-color[node];
                    queue.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
};