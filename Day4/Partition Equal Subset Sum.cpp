//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0;i<N;i++)
        {
            sum += arr[i];
        }
        if(sum % 2 != 0) return 0;
        vector<vector<bool>> dp(N+1,vector<bool>(sum + 1,false));
        for(int i = 0;i<N;i++) {dp[i][arr[i]] = true;dp[i][0] = true;}
        for(int j = 0;j<=sum/2;j++)
        {
            for(int i = 1;i<N;i++)
            {
                if(j >= arr[i])
                dp[i][j] = dp[i][j] or dp[i-1][j-arr[i]];
                dp[i][j] = dp[i][j] or dp[i-1][j];
            }
        }
        if(dp[N-1][sum/2]) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends