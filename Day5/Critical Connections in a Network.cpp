class Solution {
    private: 
    int timer = 1;
    private:
    void dfs(int i,int par,vector<int> adj[],vector<int>& low,vector<int>& intime,vector<int>& vis,vector<vector<int>>& ans)
    {
        vis[i] = 1;
        low[i]=timer;
        intime[i] = timer;
        timer = timer + 1;
        for(auto c: adj[i])
        {
            if(c == par) continue;
            if(vis[c] == 0)
            {
                dfs(c,i,adj,low,intime,vis,ans);
                low[i] = min(low[c],low[i]);
                if(intime[i] < low[c])
                {
                    ans.push_back({i,c});
                }
            }
            else
            {
                low[i] = min(low[c],low[i]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        vector<int> low(n);
        vector<int> intime(n);
        vector<int> adj[n];
        for(int i = 0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
    vector<vector<int>> ans;
    dfs(0,-1,adj,low,intime,vis,ans);
    return ans;
    }
};
