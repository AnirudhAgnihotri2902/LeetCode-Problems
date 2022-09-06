class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int len = 0;
        int prev = 0;
        int maxi = 0;
        for(int i =0; i<n; i++){
            if(nums[i] == 0){
                count++;
                cout<<i<<" "<<prev<<" "<<len<<" "<<count<<endl;
                if(count>1){
                   len=i-prev-1;
                    prev = i;
                    count = 1;
                }
                else{
                    prev = i;
                }
            }
            else{
                len++;
                maxi = max(len, maxi);
            }
        }
        if( maxi== n)maxi--;
        return maxi;
        
    }
};