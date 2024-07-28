class Solution {
public:
    int rec(string& s,int i,int j,vector<vector<int>>& dp)
    {
        if(i >= j) return 0;
        int ans = 1e4;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j])
        {
            i++;
            j--;
            ans = min(rec(s,i,j,dp),ans);
        }
        else
        {
            ans = min(rec(s,i,j-1,dp)+1,ans);
            ans = min(rec(s,i+1,j,dp)+1,ans);
        }
        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return rec(s,0,s.size()-1,dp);   
    }
};