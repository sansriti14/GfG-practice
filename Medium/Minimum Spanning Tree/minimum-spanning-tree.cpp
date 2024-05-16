//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet {
    vector<int> parent, rank, size;
    
    public:
        DisjointSet (int V) {
            parent.resize(V+1);
            rank.resize(V+1, 0);
            size.resize(V+1, 1);
            
            for(int i=0; i<V; i++)
                parent[i] = i;
        }
        
        int find_ult_parent (int node) {
            if(parent[node] == node)
                return node;
            return parent[node] = find_ult_parent(parent[node]);
        }
        
        void unionByRank (int u, int v) {
            int parent_u = find_ult_parent(u);
            int parent_v = find_ult_parent(v);
            
            if(parent_u == parent_v) return;
            
            if(rank[parent_u] < rank[parent_v]) {
                parent[parent_u] = parent_v;
            }
            
            else if(rank[parent_v] < rank[parent_u])
                parent[parent_v] = parent_u;
            
            else {
                parent[parent_v] = parent_u;
                rank[parent_u]++;
            }
        }
        
        void unionBySize(int u, int v) {
            int parent_u = find_ult_parent(u);
            int parent_v = find_ult_parent(v);
            
            if(parent_u == parent_v) return;
            
            if(size[parent_u] < size[parent_v]) {
                parent[parent_u] = parent_v;
                size[parent_v] += size[parent_u];
            }
            else {
                parent[parent_v] = parent_u;
                size[parent_u] += size[parent_v];
            }
        }
        
};

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
            for(int i=0; i<V; i++) {
            for(auto it: adj[i]) {
                edges.push_back({it[1], {i, it[0]}});
            }
        }
        
        DisjointSet dset(V);
        sort(edges.begin(), edges.end());
        
        int mst_weight = 0;
        for(auto it: edges) {
            int weight = it.first;
            int node = it.second.first;
            int adjNode = it.second.second;
            
            if(dset.find_ult_parent(node) != dset.find_ult_parent(adjNode)) {
                mst_weight += weight;
                dset.unionByRank(node, adjNode);
            }
        }
        return mst_weight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends