//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:

    long long countPaths(int row, int col, int n, int k, vector<vector<int>> &arr, vector<vector<vector<int>>>& dp) {
        if(row >= n || col >= n) return 0;
        if(k < 0) return 0;

        if(row == n - 1 && col == n - 1) return (k == arr[row][col]);
        if(dp[row][col][k] != -1) return dp[row][col][k];
        
        return dp[row][col][k] = countPaths(row + 1, col, n, k - arr[row][col], arr, dp) +  countPaths(row, col + 1, n, k - arr[row][col], arr, dp);
    }
    
public:
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (n, vector<int>(k + 1, -1)));
        return countPaths(0, 0, n, k, arr, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends