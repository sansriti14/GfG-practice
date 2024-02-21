//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int count(int i, int j, int isTrue, string& s, vector<vector<vector<int>>>& dp) {
        if(i > j) return 0;
        if(i == j) {
            return (isTrue) ? (s[i] == 'T') ? 1 : 0 : (s[i] == 'F') ? 1 : 0 ;
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int ans = 0;
        for(int k = i + 1; k < j; k += 2) {
            int lt = count(i, k - 1, 1, s, dp);
            int lf = count(i, k - 1, 0, s, dp);
            int rt = count(k + 1, j, 1, s, dp);
            int rf = count(k + 1, j, 0, s, dp);
            
            if(s[k] == '&') {
                ans += (isTrue) ? (lt * rt) : (lt * rf + lf * rt + lf * rf); 
            }
            
            else if(s[k] == '|') {
                ans += (isTrue) ? (lt * rt + lt * rf + lf * rt) : (lf * rf);
            }
            
            else ans += (isTrue) ? (lt * rf + lf * rt) : (lt * rt + lf * rf);
        }
        
        return dp[i][j][isTrue] = ans % 1003;
    }
    
public:
    int countWays(int n, string s){
        vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (n + 1, vector<int> (2, -1)));

        return count(0, n - 1, 1, s, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends