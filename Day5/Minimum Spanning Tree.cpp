//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	class dsu
	{
	   public:
	   vector<int> par;
	   vector<int> size;
	   dsu(int n)
	   {
	       par.resize(n,0);
	       size.resize(n,0);
	       for(int i = 0;i<n;i++) par[i] = i;
	   }
	   int find_par(int u)
	   {
	       if(par[u] == u) return u;
	       return par[u] = find_par(par[u]);
	   }
	   void union_size(int u,int v)
	   {
	       int par_u = find_par(u);
	       int par_v = find_par(v);
	       if(par_u == par_v) return;
	       if(size[par_u] > size[par_v])
	       {
	           par[par_v] = par_u;
	           size[par_u] += size[par_v];
	       }
	       else
	       {
	           par[par_u] = par_v;
	           size[par_v] += size[par_u];
	       }
	   }
	};
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> v;
        for(int i = 0;i<V;i++)
        {
            for(auto c: adj[i])
            {
                v.push_back({c[1],{c[0],i}});
            }
        }
        sort(v.begin(),v.end());
        int sum = 0;
        dsu ds(V);
        for(int i = 0;i<v.size();i++)
        {
            int u = v[i].second.first;
            int v1 = v[i].second.second;
            int wt = v[i].first;
            int u_par = ds.find_par(u);
            int v_par = ds.find_par(v1);
            if(u_par == v_par) continue;
            ds.union_size(u,v1);
            sum += wt;
        }
        return sum;
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