class Solution {
public:
    bool isvalid(int i,int j,int n,int m)
    {
        if(i<n and j<m and i>=0 and j>=0) return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(grid[i][j] == '0') return;
        if(grid[i][j] == '1') grid[i][j] = '2';
        int x[] = {1,-1,0,0};
        int y[] =  {0,0,1,-1};
        for(int k = 0;k<4;k++)
        {
            if(isvalid(i+x[k],j+y[k],grid.size(),grid[0].size()) and grid[i+x[k]][j+y[k]] != '2') dfs(grid,i+x[k],j+y[k]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '1') {cnt++;dfs(grid,i,j);}
            }
        }
        return cnt;
    }
};