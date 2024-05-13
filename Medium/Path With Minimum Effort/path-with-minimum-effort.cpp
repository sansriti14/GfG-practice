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
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        vector<vector<int>> abs_diffs (n, vector<int> (m, 1e9));
        abs_diffs[0][0] = 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!pq.empty()) {
            int curr_diff = pq.top().first;
            int curr_row = pq.top().second.first;
            int curr_col = pq.top().second.second;
            pq.pop();
            
            for(int i=0; i<4; i++) {
                int nrow = curr_row + drow[i];
                int ncol = curr_col + dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m) {
                    int diff = max(abs(heights[curr_row][curr_col] - heights[nrow][ncol]), curr_diff);
                    if(diff < abs_diffs[nrow][ncol]) {
                        abs_diffs[nrow][ncol] = diff;
                        pq.push({diff, {nrow, ncol}});
                    }
                }
            }
        }
        
        return abs_diffs[n-1][m-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends