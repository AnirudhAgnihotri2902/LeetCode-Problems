// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int solve(vector<int>& arr, int prev, int i, vector<vector<int>>&dp ){
	    if(i==arr.size()){
	        return 0;
	    }
	    if(dp[i][prev+1]!=-1){
	        return dp[i][prev+1];
	    }
	    int first = INT_MIN, second = INT_MIN;
	    first = solve(arr,prev,i+1,dp);
	    if(prev == -1 || arr[prev]<arr[i]){
	        second = arr[i]+ solve(arr, i,i+1,dp);
	    }
	    return dp[i][prev+1] = max(first, second);
	}
	int maxSumIS(int a[], int n){
	    vector<int>arr(n,0);
	    for(int i = 0; i<n; i++){
	        arr[i] = a[i];
	    }
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	    int ans = solve(arr, -1,0,dp);
	    return ans;
	    
	    
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends