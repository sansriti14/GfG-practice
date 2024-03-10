//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_map<char, int> mp;
	    for(auto ch: str) {
	        mp[ch]++;
	    }
	    
	    string ans = "";
	    for(int i = str.length() - 1; i >= 0; i--) {
	        if(mp[str[i]] > 1) mp[str[i]]--;
	        else if(mp[str[i]] == 1) ans += str[i];
	    }
	    
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends