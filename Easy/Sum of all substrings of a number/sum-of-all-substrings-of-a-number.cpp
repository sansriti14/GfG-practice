//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        long long mod = 1e9 + 7;
        long long int ans = 0;
        long long temp = 0 ;
        
        for(int i = 0; i < s.length(); i++){
            int digit = s[i] - '0';
            long long int unit = digit * (i + 1);
            temp = (((temp * 10) % mod) + unit) % mod;
            ans = (ans + temp) % mod;
            
        }
        
        return ans % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends