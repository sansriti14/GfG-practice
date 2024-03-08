//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    bool sameFreq(string s) {
    unordered_map<char, int> mp;
        int max_freq = 0;
        for(auto ch: s) {
            max_freq = max(max_freq, ++mp[ch]);
        }
        
        int count = 0;
        for(auto it: mp){
            if(it.second == max_freq){
                count++;
            }
        }
        
        if(count == mp.size()) return true;
        
        for(auto i: mp) {
            mp[i.first]--;
            
            unordered_set<int> st;
            count = 1;
            for(auto j: mp){
                if(j.second > 0) st.insert(j.second);
                if(st.size() > 1) {
                    count = 0;
                    break;
                }
            }
            
            if(count >= 1) return 1;
            
            mp[i.first]++;
        }
        
        return false;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends