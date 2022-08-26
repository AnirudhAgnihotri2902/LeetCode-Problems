class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>queue;
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(!queue.empty() && (queue.front() == i-k))queue.pop_front();
            while(!queue.empty() && nums[i]>=nums[queue.back()]){
                //cout<<i<<" "<<nums[i]<<" "<<nums[queue.back()]<<endl;
                queue.pop_back();
            }
            queue.push_back(i);
            //cout<<i<<" "<<queue.front()<<endl;
            if(i>=k-1){
                ans.push_back(nums[queue.front()]);
            }
        }
        return ans;
    }
};