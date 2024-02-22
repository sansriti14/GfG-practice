//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    private:
    int countOccurences(int s_index, int t_index, string& s, string& t, vector<vector<int>>& dp) {
        if(t_index == t.length()) return 1;
        if(s_index == s.length()) return 0;
        
        if(dp[s_index][t_index] != -1) return dp[s_index][t_index];
        
        int mod = 1e9 + 7;
        int not_pick = 0, pick = 0;
        
        not_pick = countOccurences(s_index + 1, t_index, s, t, dp);
        if(s[s_index] == t[t_index]) {
            pick = countOccurences(s_index + 1, t_index + 1, s, t, dp);
        }
        
        return dp[s_index][t_index] = (pick + not_pick) % mod;
    }
    
    public:
    int subsequenceCount(string s, string t)
    {
        vector<vector<int>> dp (s.length(), vector<int> (t.length(), -1));
        return countOccurences(0, 0, s, t, dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends