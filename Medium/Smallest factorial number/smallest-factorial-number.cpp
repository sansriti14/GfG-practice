//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
            int low = 0, high = 5*n;
            int ans = 0;
            while(low <= high) {
                int mid = (low + high) >> 1;
                int count = 0;
                int pow = 5;
                while(mid/pow > 0) {
                    count += mid/pow;
                    pow *= 5;
                }
                
                if(count >= n) {
                    ans = mid;
                    high = mid-1;
                }
                
                else low = mid+1;
            }
            
            return ans;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends