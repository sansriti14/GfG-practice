//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cities (n, vector<int> (n, 1e8));
        
        for(auto it: edges) {
            cities[it[0]][it[1]] = it[2];
            cities[it[1]][it[0]] = it[2];
        }
        
        for(int i = 0; i < n; i++) cities[i][i] = 0;
        
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cities[i][j] = min(cities[i][j], cities[i][via] + cities[via][j]);
                }
            }
        }
        
        int max_cities = n;
        int city = -1;
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(cities[i][j] <= distanceThreshold) 
                    count++;
            }
            
            if(count <= max_cities) {
                max_cities = count;
                city = i;
            }
        }
        
        return city;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends