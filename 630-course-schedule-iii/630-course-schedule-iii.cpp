class Solution {
public:
    static bool cmp(vector<int>&a,vector<int> &b){
        return (a[1]< b[1]);
    }
    
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<vector<int>>queue;
        int time = 0;
        for(int i = 0; i<courses.size(); i++){
            if(time+courses[i][0]<=courses[i][1]){
                queue.push(courses[i]);
                time+=courses[i][0];
            }
            else{
                if(!queue.empty() && queue.top()[0]>courses[i][0]){
                    vector<int>temp = queue.top();
                    time-=temp[0];
                    queue.pop();
                    queue.push(courses[i]);
                    time+=courses[i][0];
                }
            }
        }
        return queue.size();
    }
};