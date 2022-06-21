// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(vector<int>&arr, int prev, int i, vector<vector<int>> &dp){
        if(i == arr.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int first = INT_MIN;
        int second = INT_MIN;
        first = solve(arr,prev,i+1,dp);
        if(prev==-1 || arr[prev]<arr[i]){
            second = 1+solve(arr, i,i+1, dp);
        }
        return dp[i][prev+1] = max(first,second);
        
    }
    int longestSubsequence(int n, int a[])
    {
       vector<int>arr(n,0);
       for(int i = 0; i<n; i++){
           arr[i] = a[i];
       }
       vector<vector<int>>dp(n,vector<int>(n+1,-1));
       int ans = solve(arr,-1,0,dp);
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends