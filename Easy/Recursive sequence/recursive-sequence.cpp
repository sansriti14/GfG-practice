//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        long long ans = 0;
        int mod = 1e9 + 7;
        int j = 1;
        for(int i = 1; i <= n; i++) {
            long long ele = 1;
            for(int k = 1; k <= i; k++) {
                ele = (ele * j) % mod;
                j++;
            }
            
            ans = (ans + ele) % mod;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends