//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int maxProfit(vector<int>&price){
            int buy1 = INT_MAX;
            int sell1 = INT_MIN;
            int buy2 = INT_MAX;
            int sell2 = INT_MIN;
            
            for (int i = 0; i < price.size(); i++) {
                buy1 = min(buy1, price[i]);
                sell1 = max(sell1, price[i] - buy1);
                buy2 = min(buy2, price[i] - sell1);
                sell2 = max(sell2, price[i] - buy2);
            }
            
            return sell2;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends