class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans = 0;
        for(int i = 0;i<matrix[0].size();i++) dp[0][i] = matrix[0][i]-'0';
        for(int j = 0;j<matrix.size();j++) dp[j][0] = matrix[j][0]-'0';
        for(int i = 1;i<matrix.size();i++)
        {
            for(int j = 1;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '0') continue;
                else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};