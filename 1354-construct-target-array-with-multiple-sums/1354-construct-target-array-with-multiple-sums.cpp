class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>queue;
        if(target.size() == 1){
            if(target[0] == 1){
                return true;
            }
            return false;
        }
        long long int sum = 0;
        for(int i = 0; i<target.size(); i++){
            queue.push(target[i]);
            sum+=target[i];
        }
        while(queue.top()!=1){
            int curr = queue.top();
            queue.pop();
            if (sum - curr == 1) return true;
            int x = curr % (sum - curr);
            sum = sum - curr + x;
            if (x == 0 || x == curr) return false;
            else queue.push(x);
        }
        return true;
    }
};