//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
private:
    int isPossibleToBreak(int index, const string& s, unordered_set<string>& dictionary, vector<int>& dp) {
        int n = s.length();
        if(n == 0) return 1;
        if(dictionary.find(s) != dictionary.end()) return 1;
        
        if(dp[index] != -1) return dp[index];
        
        for(int length = 1; length <= n; length++) {
            if(dictionary.find(s.substr(0, length)) != dictionary.end()) {
                if(isPossibleToBreak(index + length, s.substr(length), dictionary, dp) == 1)
                    return dp[index] = 1;
            }
        }
        
        return dp[index] = 0;
    }
    
public:
    int wordBreak(int n, string s, vector<string> &wordDictionary) {
        unordered_set<string> dictionary (begin(wordDictionary), end(wordDictionary));
        if(dictionary.find(s) != dictionary.end()) return 1;
        
        int m = s.length();
        vector<int> dp (m + 1, -1);
        return isPossibleToBreak(0, s, dictionary, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends