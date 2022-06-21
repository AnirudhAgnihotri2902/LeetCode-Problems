// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(string &s1, string&s2, int i, int j, vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MIN;
        if(s1[i] == s2[j]){
            ans= 1+solve(s1,s2,i-1,j-1,dp);
        }
        else{
            int first = solve(s1, s2, i-1,j,dp);
            int second = solve(s1,s2,i,j-1,dp);
            ans = max(first,second);
        }
        return dp[i][j] = ans;
        
    }
    int lcs(int x, int y, string s1, string s2){
        vector<vector<int>>dp(x,vector<int>(y,-1));
        int first = solve(s1, s2, x-1, y-1, dp);
        return first;
        
        // your code here
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends