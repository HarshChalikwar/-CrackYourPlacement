//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isValid(int i,int j)
  {
      if(i<4 and j<3 and i>=0 and j>=0) return true;
      return false;
  }
  long long rec(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<long long>>& dp)
  {
      if(matrix[i][j] == -1 ) return 0;
      if(n == 1) return 1;
      if(dp[n][matrix[i][j]] != -1) return dp[n][matrix[i][j]];
      int x[] = {1,-1,0,0,0};
      int y[] = {0,0,-1,1,0};
      long long ans = 0;
      for(int k = 0;k<5;k++)
      {
          int i_n = i + x[k];
          int j_n= j+ y[k];
          if(isValid(i_n,j_n))
          {
              ans += rec(i_n,j_n,n-1,matrix,dp);
          }
      }
      return dp[n][matrix[i][j]] = ans;
      
  }
    long long getCount(int n) {
        vector<vector<int>> matrix(4,vector<int>(3,0));
        vector<vector<long long>> dp(n+1,vector<long long>(10,-1));
        matrix[0][0] = 1;
        matrix[0][1] = 2;
        matrix[0][2] = 3;
        matrix[1][0] = 4;
        matrix[1][1] = 5;
        matrix[1][2] = 6;
        matrix[2][0] = 7;
        matrix[2][1] = 8;
        matrix[2][2] = 9;
        matrix[3][0] = -1;
        matrix[3][1] = 0;
        matrix[3][2] = -1;
        long long ans = 0;
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<3;j++)
            {
                   ans += rec(i,j,n,matrix,dp);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends