//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	private:
	    void findSubsequences(int index, string &s, vector<string> &ans, string temp) {
	        if(index == s.size()) {
	            if(temp != "") ans.push_back(temp);
	            return;
	        }
	        
	        temp += s[index];
	        findSubsequences(index + 1, s, ans, temp);
	        temp.pop_back();
	        findSubsequences(index + 1, s, ans, temp);
	    }
	    
    public:
		vector<string> AllPossibleStrings(string s) {
		    vector<string> ans;
		    findSubsequences(0, s, ans, "");
		    
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends