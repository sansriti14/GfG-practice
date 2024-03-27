//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
private:
    bool isValid(int curr_row, int curr_col, int r, int c) {
        return (curr_row >= 0 && curr_col >= 0 && curr_row < r && curr_col < c);
    }
    
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(mat[i][j] == 0) {
                    if(i > 0) mat[i - 1][j] = -1;
                    if(j > 0) mat[i][j - 1] = -1;
                    if(i < r - 1) mat[i + 1][j] = -1;
                    if(j < c - 1) mat[i][j + 1] = -1;
                }
            }
        }
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> distance (r, vector<int> (c, 1e8));
        
        for(int i = 0; i < r; i++) {
            if(mat[i][0] == 1) q.push({1, {i, 0}});
        }
        
        int delta_row[] = {-1, 0, 1};
        int delta_col[] = {0, 1, 0};
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int curr_distance = it.first;
            int curr_row = it.second.first;
            int curr_col = it.second.second;
            
            if(curr_col == c - 1) return curr_distance;
            
            for(int i = 0; i < 3; i++) {
                int adj_row = curr_row + delta_row[i];
                int adj_col = curr_col + delta_col[i];
                
                if(isValid(adj_row, adj_col, r, c) && mat[adj_row][adj_col] == 1 && distance[adj_row][adj_col] > curr_distance + 1) {
                    q.push({curr_distance + 1, {adj_row, adj_col}});
                    distance[adj_row][adj_col] = curr_distance + 1;
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends