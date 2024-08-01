//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int i,int j,int n,int m)
    {
        if(i<n and i>=0 and j<m and j>=0) return true;
        return false;
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        int t = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) t = 1;
            }
        }
        if(q.empty() and  t== 0) return 0;
        int cnt = 0;
        while(!q.empty())
        {
            int s  = q.size();
            cnt++;
            while(s)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                int x[] = {0,0,-1,1};
                int y[] = {1,-1,0,0};
                for(int k =0 ;k<4;k++)
                {
                    int i_n = x[k] + i;
                    int j_n = y[k] + j;
                    if(isValid(i_n,j_n,grid.size(),grid[0].size()))
                    {
                        if(grid[i_n][j_n] == 1)
                        {
                            grid[i_n][j_n] = 2;
                            q.push({i_n,j_n});
                        }
                    }
                }
                s--;
            }
        }
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        return cnt - 1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends