//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int n = s.length();
        if(n == 1) return s;
        
        vector<string> words;
        int i = 0;
        while(i < n) {
            int j = i;
            string temp = "";
            while(j < n && s[j] != '.') {
                temp += s[j];
                j++;
            }
            
            words.push_back(temp);
            i = j + 1;
        }
        
        string ans = "";
        for(int word = words.size() - 1; word >= 0; word--) {
            ans += words[word];
            ans += '.';
        }
        
        ans.pop_back();
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends