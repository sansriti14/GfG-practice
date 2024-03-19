//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class DisjointSet {
  public:
    vector<int> parent, size;
    DisjointSet (int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    
    int findParent (int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    int unionBySize(int u, int v) {
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        
        int temp = size[parent_u] * size[parent_v];
        
        if(parent_u == parent_v) return temp;
        
        if(size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
        
        return temp;
    }
};

class Solution{
	public:
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
        for(int i = 0; i < n - 1; i++) {
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int weight = edges[i][2];
	        edges[i][0] = weight;
	        edges[i][1] = u;
	        edges[i][2] = v;
	    }
	    
	    sort(begin(edges), end(edges));
	    DisjointSet ds(n + 1);
	    
	    map<int, int> mp;
	    int value = 0;
	    for(int i = 0; i < n - 1; i++) {
	        int u = edges[i][1];
	        int v = edges[i][2];
	        int weight = edges[i][0];
	        mp[weight] = ds.unionBySize(u, v) + value;
	        value = mp[weight];
	    }
	    
	    vector<int> ans(q, 0);
	    for(int i = 0; i < q; i++) {
	        auto it = mp.upper_bound(queries[i]);
	        if(it != mp.begin()) {
	            it--;
	            ans[i] = it->second;
	        }
	    }
	    
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
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends