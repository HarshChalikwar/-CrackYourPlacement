class Solution {
public:
    bool isvalid(int i,int j,vector<vector<int>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size()) return false;
        return true;
    }
    int rec(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j)
    {
        if(vis[i][j] != -1) return vis[i][j];
        if(i == grid.size()-1 and j== grid[0].size()-1) return grid[grid.size()-1][grid[0].size()-1];
        int sum = 1e8;
        if(isvalid(i+1,j,grid))
            sum = min(sum,rec(grid,vis,i+1,j)+grid[i][j]);
        if(isvalid(i,j+1,grid))
            sum = min(sum,rec(grid,vis,i,j+1)+grid[i][j]);
        return vis[i][j] = sum;
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        return rec(grid,vis,0,0);
    }
};