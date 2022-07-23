class Solution {
public:
    void mergesort(vector<pair<int,int>> &nums,int i,int j,vector<int> &ans){
        if(i==j) return;
        int mid=(i+j)/2;
        mergesort(nums,i,mid,ans);
        mergesort(nums,mid+1,j,ans);
        merge(nums,i,j,mid,ans);
    }
    void merge(vector<pair<int,int>> &nums,int i,int j,int mid,vector<int> &ans){
        vector<pair<int,int>> t(j-i+1);
        int a=i,b=mid+1,k=0;
        while(a<=mid and b<=j){
            if(nums[a].first>nums[b].first){
            ans[nums[a].second]+=(j-b+1);
            t[k++]=nums[a++];
            }
            else t[k++]=nums[b++];
        }
        while(a<=mid) t[k++]=nums[a++];
        while(b<=j) t[k++]=nums[b++];
        for(int c=0;c<k;c++) nums[i++]=t[c];
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> t;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++) t.push_back({nums[i],i});
        mergesort(t,0,n-1,ans);
        return ans;
    }
};