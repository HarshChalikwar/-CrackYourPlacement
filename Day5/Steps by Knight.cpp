//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    private:
    int steps =0;
    int vis[1001][1001];
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool checkifintbounds(int i, int j, int n)
    {
        if(i>0 && i<=n && j>0 && j<=n)
        {
            return true;
        }
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    memset(vis,0,sizeof(vis));
	    int size = 0;
	    // Code here
	    queue<pair<int,int>> p;
	    p.push({KnightPos[0],KnightPos[1]});
	    vector<pair<int,int>> v = {{-1,-2},{-1,2},{1,-2},{1,2},{2,1},{-2,-1},{-2,1},{2,-1}};
	    int f= 0;
	    if(KnightPos == TargetPos) return 0;
	    while(!p.empty())
	    {
	        int m = p.size();
	        for(int i = 0;i<m;i++)
	        {
	            auto k = p.front();
	            p.pop();
	            if(k.first == TargetPos[0] and k.second == TargetPos[1]) 
	                {
	                    f =1;
	                    break;
	                }
	            for(auto j : v)
	            {
	                j.first = k.first + j.first;
	                j.second = k.second + j.second;
	                if(checkifintbounds(j.first,j.second,N))
	                {
	                if(vis[j.first][j.second] == 0)
	                {
	                    p.push(j);
	                    vis[j.first][j.second] = 1;
	
	                }
	                }
	            }
	        }
	        if(f == 1) break;
	        steps++;
	        
	    }
	   if(steps) return steps;
	   return -1;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends