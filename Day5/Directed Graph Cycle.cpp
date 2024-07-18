//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indeg(V,0);
        for(int i = 0;i<V;i++)
        {
            for(auto c: adj[i])
            {
                indeg[c]++;
            }
        }
        queue<int> q;
        for(int i= 0;i<V;i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            for(auto c : adj[t])
            {
                if(indeg[c] > 0)
                {
                    indeg[c]--;
                    if(indeg[c] == 0) q.push(c);
                }
            }
        }
        for(int i = 0;i<V;i++)
        {
            if(indeg[i]) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends