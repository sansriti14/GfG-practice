//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        int m = s.length();
        
        while(r--) {
            string str = "";
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '0') str += "01";
                else str += "10";
                
                if(str.length() >= m) break;
            }
            
            s = str;
        }
        
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends