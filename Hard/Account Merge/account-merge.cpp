//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DisjointSet {
    public:
        vector<int> parent, size;
        DisjointSet (int V) {
            parent.resize(V+1);
            size.resize(V+1, 1);
            
            for(int i=0; i<V; i++)
                parent[i] = i;
        }
        
        int findParent (int node) {
            if(parent[node] == node)
                return node;
            return parent[node] = findParent(parent[node]);
        }
        
        void unionBySize(int u, int v) {
            int parent_u = findParent(u);
            int parent_v = findParent(v);
            
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

//User function Template for C++
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet djSet(n);
        
        unordered_map<string, int> mapMailtoName;
        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                if(mapMailtoName.find(accounts[i][j]) == mapMailtoName.end()) {
                    mapMailtoName[accounts[i][j]] = i;
                }
                
                else {
                    djSet.unionBySize(mapMailtoName[accounts[i][j]], i);
                }
            }
        }
        
        vector<string> mergedMails[n];
        for(auto it: mapMailtoName) {
            string mail = it.first;
            int parent_node = djSet.findParent(it.second);
            mergedMails[parent_node].push_back(mail);
        }
        
        vector<vector<string>> mergedDetails;
        for(int i=0; i<n; i++) {
            if(mergedMails[i].size() == 0) continue;
            
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMails[i]) 
                temp.push_back(it);
                
            mergedDetails.push_back(temp);
        }
        
        reverse(mergedDetails.begin(), mergedDetails.end());
        return mergedDetails;
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
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends