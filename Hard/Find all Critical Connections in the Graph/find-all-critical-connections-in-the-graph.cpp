//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dfs(vector<int> graph[], int i, vector<int>& rank, vector<vector<int>>& ans, int prev_rank, int n) {
        rank[i] = prev_rank + 1;
        int t = INT_MAX;
        
        for(const auto& adjNode: graph[i]) {
            if(rank[adjNode] == -1) {
                
                int k = dfs(graph, adjNode, rank, ans, prev_rank + 1, n);
                if( k > rank[i]) {
                    ans.push_back({min(i, adjNode), max(i, adjNode)});
                }
                
                t = min(t, k);
                
            } 
            
            else if(rank[adjNode] == n+1) continue;
            
            else if(rank[adjNode] != prev_rank) {
                t = min(t, rank[adjNode]);
            }
        }
        
        rank[i] = n + 1;
        return t;
    }
    
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    vector<vector<int>> ans;
	    vector<int> rank(v, -1);
	    
	    int k = dfs(adj, 0, rank, ans, 0, v);
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends