//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    private:
    int merge(int arr[], int temp[], int l, int m, int r) {
        int i, j, k;
        int count = 0;
        i = l; 
        j = m; 
        k = l;
        
        while((i <= m - 1) && (j <= r)) {
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                count += m - i; 
            }
        }
        
        while(i <= m - 1) temp[k++] = arr[i++];
        while(j <= r) temp[k++] = arr[j++];
        for (i = l; i <= r; i++) arr[i] = temp[i];
        
        return count;
    }
    
    int mergeSort(int arr[], int temp[], int l, int r) {
        int m;
        int count = 0;
        if(r > l) {
            m = (r + l) / 2;
            count += mergeSort(arr, temp, l, m);
            count += mergeSort(arr, temp, m + 1, r);
            count += merge(arr, temp, l, m + 1, r);
        }
        
        return count;
    }
    
    public:
    int countPairs(int arr[] , int n ) 
    {
        for(int i = 0; i < n; i++) {
            arr[i] = i * arr[i];
        }
        
        int temp[n];
        int ans = mergeSort(arr, temp, 0, n - 1);
        
        return ans;     
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends