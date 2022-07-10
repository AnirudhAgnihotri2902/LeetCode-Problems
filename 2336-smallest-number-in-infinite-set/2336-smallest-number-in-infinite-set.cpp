class SmallestInfiniteSet {
public:
    int count = 1;
    priority_queue<int, vector<int>, greater<int>>queue;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(queue.size()>0 && queue.top()<=count){
            if(queue.top() == count){
                int ans = count;
                count++;
                while(queue.size()>0 && queue.top() == ans){
                    queue.pop();
                }
                return count;
            }
            int ans = queue.top();
            while(queue.size()>0 && queue.top() == ans){
                queue.pop();
            }
            return ans;
        }
        
        int ans = count;
        while(queue.size()>0 && queue.top() == ans){
            queue.pop();
        }
        count++;
        return ans;
    }
    
    void addBack(int num) {
        if(num<count){
            queue.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */