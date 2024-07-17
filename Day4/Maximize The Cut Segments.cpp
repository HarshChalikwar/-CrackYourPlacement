//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,-1e9);
        if(x<=n)
        dp[x] = 1;
        if(y<=n)
        dp[y] = 1;
        if(z<=n)
        dp[z] = 1;
        for(int i = 0;i<n+1;i++)
        {
            if(i > x)
            {
                dp[i] = max(dp[i],dp[i-x] + dp[x]);
            }
            if(i > y) dp[i] = max(dp[i],dp[y] + dp[i-y]);
            if(i > z) dp[i] = max(dp[i],dp[z] + dp[i-z]);
        }
        if(dp[n] < 0) return 0;
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends