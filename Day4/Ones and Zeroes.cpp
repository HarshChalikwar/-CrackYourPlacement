class Solution {
    int dp[601][101][101];
public:
    int dy(vector<string>& strs,int m,int n,int i)
    {
        if(i == strs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int m1 = 0,n1 = 0;
        for(auto k: strs[i])
        {
            if(k == '0') m1++;
            if(k == '1') n1++;
        }
        int max1 = 0;
        if(m1 <= m and n1 <= n)
        max1 = max(max1,dy(strs,m-m1,n-n1,i+1) + 1);
        max1 = max(max1,dy(strs,m,n,i+1));
        return dp[i][m][n] = max1;

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return dy(strs,m,n,0);
    }
};