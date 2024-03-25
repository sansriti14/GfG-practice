//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    void findNBitBinary(int i, string str, int countZeros, int countOnes, int n, vector<string>& ans) {
        if (countZeros > countOnes) return;
        if(i == n) {
            ans.push_back(str);
            return;
        }
        
        findNBitBinary(i + 1, str + "1", countZeros, countOnes + 1, n, ans);
        findNBitBinary(i + 1, str + "0", countZeros + 1, countOnes, n, ans);
    }
    
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    findNBitBinary(1, "1", 0, 1, n, ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends