class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int arr[m+n];
        for(int i = 0; i<m;i++){
            arr[i] = nums1[i];
        }
        
        int  i = 0;
        int j = 0;
        int index = 0;
        while(i<m && j<n){
            if (arr[i]<=nums2[j]){
                nums1[index] = arr[i];
                i++;
            }
            else{
                nums1[index] = nums2[j];
                j++;
            }
            index+=1;
        }
        
        while(i<m){
            nums1[index] = arr[i];
            i++;
            index++;
        }
        while(j<n){
            nums1[index] = nums2[j];
            j++;
            index++;
        } 
    }
};