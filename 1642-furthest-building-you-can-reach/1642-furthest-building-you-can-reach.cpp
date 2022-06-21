class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>queue;
        int index = 1;
        for(; index<heights.size(); index++){
            if(heights[index]<=heights[index-1]){
                continue;
            }
            if(heights[index]>heights[index-1]){
                int diff = heights[index]-heights[index-1];
                bricks-=diff;
                queue.push(diff);
                if(bricks<0){
                    if(ladders>0){
                        ladders--;
                        bricks+=queue.top();
                        queue.pop();
                    }
                    else if(bricks<0 || ladders<=0){
                        return index-1;
                    }
                }
            }
        }
        return index-1;
    }
};