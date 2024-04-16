//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int> rightmax(n, 0);
        vector<int> rightmin(n, 0);
       
        rightmax[n - 1] = arr[n - 1];
        rightmin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], arr[i]);
            rightmin[i] = min(rightmin[i + 1], arr[i]);
        }
       
        int ans = INT_MAX;
        int leftmax = INT_MIN, leftmin = INT_MAX;
        int j = 0;
        
        for (int i = k; i <= n; i++) {
            int minval, maxval;
            if(i <= n - 1 ) {
                minval = min(leftmin, rightmin[i]);
                maxval = max(leftmax, rightmax[i]);
            }
            
            else {
            minval = leftmin;
            maxval = leftmax;
            }
            
            ans = min(ans, maxval - minval);
            
            leftmax = max(leftmax, arr[j]);
            leftmin = min(leftmin, arr[j]);
            
            j++;
        }
     
        return ans; 
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends