class Solution {
public:
    int rec(vector<int>& coins,int wt,vector<int>& dp)
    {
        if(wt == 0) return 0;
        if(dp[wt] != -1) return dp[wt];
        int sum = 1e5;
        for(int j = 0;j<coins.size();j++)
        {
            if(coins[j] <= wt) sum = min(sum,rec(coins,wt-coins[j],dp)+1);
        }
        return dp[wt] = sum;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int cnt =    rec(coins,amount,dp);
        if(cnt == 1e5) cnt = -1;
        return cnt;
    }
};