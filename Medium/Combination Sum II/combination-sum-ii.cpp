//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    void solve(vector<int> &arr,int n,int k, int index, int currSum, vector<int> &temp, set<vector<int>> &st) {
        if(currSum == k) {
            st.insert(temp);
            return;
        }
        
        if(index == n) return;
      
        solve(arr, n, k, index + 1, currSum, temp, st);
        
        if(currSum < k) {
            temp.push_back(arr[index]);
            solve(arr, n, k, index + 1, currSum + arr[index], temp, st);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        vector<int> temp;
        set<vector<int>> st;
        
        sort(arr.begin(),arr.end());
        
        solve(arr, n, k, 0, 0, temp, st);
        
        vector<vector<int>> ans(st.begin(),st.end());
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends