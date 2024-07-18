//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void topoSort(int i,vector<vector<int>>& adj,vector<int>& topo,vector<int>& vis)
	{
	    vis[i] = 1;
	    for(auto c: adj[i])
	    {
	        if(!vis[c])
	        {
	            topoSort(c,adj,topo,vis);
	        }
	    }
	    topo.push_back(i);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> topo;
        vector<int> vis(V,0);
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            topoSort(i,adj,topo,vis);
        }
        vector<vector<int>> adj2(V);
        for(int i = 0;i<V;i++)
        {
            for(auto k: adj[i])
            {
                adj2[k].push_back(i);
            }
        }
        vector<int> vis1(V,0);
        vector<int> topo1;
        reverse(topo.begin(),topo.end());
        int cnt = 0;
        for(int i = 0;i<topo.size();i++)
        {
            if(!vis1[topo[i]])
            {
                topoSort(topo[i],adj2,topo1,vis1);
                cnt++;
            }
        }
        return cnt;        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends