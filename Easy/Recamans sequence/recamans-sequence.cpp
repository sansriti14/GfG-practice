//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> seq (n);
        unordered_set<int> st;
        seq[0] = 0;
        st.insert(0);
        
        for(int i = 1; i < n; i++) {
            int ele = (seq[i - 1] - i < 0 || st.find(seq[i - 1] - i) != st.end()) ? seq[i - 1] + i : seq[i - 1] - i;
            seq[i] = ele;
            st.insert(ele);
        }
        
        return seq;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends