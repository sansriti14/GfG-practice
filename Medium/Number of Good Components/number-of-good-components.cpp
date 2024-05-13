//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  private:
    void dfs(int node, vector<int> list[], int& v_count, int& e_count, vector<int>& visited) {
        visited[node] = 1;
        v_count += 1;
        e_count += list[node].size();
        
        for(int i=0; i<list[node].size(); i++) {
            if(visited[list[node][i]] == 0) {
                dfs(list[node][i], list, v_count, e_count, visited);
            }
        }
        
    }
    
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int> visited(v+1, 0);
        vector<int> list[v+1];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            list[u].push_back(v);
            list[v].push_back(u);
        }
        
        int good_components = 0;
        for(int i=1; i<=v; i++){
            if(visited[i] == 0){
                int v_count = 0;
                int e_count = 0;
                dfs(i, list, v_count, e_count, visited);
                if((v_count * (v_count - 1))/2 == e_count/2) {
                    good_components++;
                }
            }
        }
        
        return good_components;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends