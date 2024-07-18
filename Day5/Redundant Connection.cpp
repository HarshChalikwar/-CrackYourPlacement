class Solution {
public:
    class dsu
    {
        public:
        vector<int> par,size;
        dsu(int n)
        {
            par.resize(n+1,0);
            size.resize(n+1,0);
            for(int i = 0;i<n;i++)
            {
                par[i]= i;
            }
        }
        int find_par(int u)
        {
            if(u == par[u]) return u;
            return par[u] = find_par(par[u]);
        }
        void union_size(int u,int v)
        {
            int par_u = find_par(u);
            int par_v = find_par(v);
            if(par_u == par_v) return ;
            else if(size[par_u] > size[par_v])
            {
                size[par_u] += size[par_v];
                par[par_v] = par_u;
            }
            else
            {
                size[par_v] += size[par_u];
                par[par_u] = par_v;
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu ds(edges.size());
        vector<int> ans;
        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v= edges[i][1];
            int u_par = ds.find_par(u);
            int v_par = ds.find_par(v);
            if(u_par == v_par) ans = {edges[i]};
            else ds.union_size(u_par,v_par);
        }
        return ans;
    }
};