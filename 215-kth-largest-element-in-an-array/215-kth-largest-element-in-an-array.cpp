class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>queue;
        for(int i = 0; i<nums.size();i++){
            if(queue.size()<k){
                queue.push(nums[i]);
            }
            else if(queue.top()<nums[i]){
                queue.pop();
                queue.push(nums[i]);
            }
        }
        return queue.top();

    }
};