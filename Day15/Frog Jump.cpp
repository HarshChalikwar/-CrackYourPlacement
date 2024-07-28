class Solution {
public:
    bool rec(int i,vector<int>& stones,int k,vector<vector<int>>& dp)
    {
        if(i == stones.size()-1) return true;
        if(dp[i][k] != -1) return (dp[i][k]);
        bool ans = false;
        for(int j = i+1;j<=stones.size()-1;j++)
        {
            int diff = stones[j] - stones[i];
            if(diff > k+1) break;
            if(diff == k-1) ans = ans or rec(j,stones,k-1,dp);
            if(diff == k) ans = ans or rec(j,stones,k,dp);
            if(diff == k+1) ans = ans or rec(j,stones,k+1,dp);
        }
        if(ans) dp[i][k] = 1;
        else dp[i][k] = 0;
        return ans;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] - stones[0] >= 2) return false;
        vector<vector<int>> dp(stones.size(),vector<int>(2001,-1));
        return rec(1,stones,1,dp);
    }
};