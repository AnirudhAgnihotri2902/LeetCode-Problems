// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>>&mat, int r, int c, vector<vector<int>>&dp){
        if(r<0|| r>=mat.size() || c<0 || c>=mat.size()){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int  first = solve(mat,r+1,c,dp);
        int second = solve(mat,r+1,c-1,dp);
        int third = solve(mat,r+1,c+1,dp);
        first = max(first,second);
        first = max(first,third);
        return dp[r][c] = mat[r][c]+first;
    }
    int maximumPath(int n, vector<vector<int>> mat)
    {
        int maxi = INT_MIN;
        vector<vector<int>>dp = mat;
        maxi = *max_element(dp[0].begin(), dp[0].end());
        // for(int i = 0; i<n; i++){
        //     int ans = solve(mat,0,i,dp); 
        //     maxi = max(ans, maxi);
        // }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == 0){
                    dp[i][j] = mat[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                }
                else if(j == n-1){
                    dp[i][j] = mat[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                }
                else 
                    dp[i][j] = mat[i][j] + max({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]});
                if(i == n-1)
                maxi = max(dp[i][j],maxi);
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends