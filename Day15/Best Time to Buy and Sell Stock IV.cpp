class Solution {
public:
    int rec(int k, vector<int>& prices, int i, bool holding, vector<vector<vector<int>>>& dp) {
        if (k == 0 || i == prices.size()) return 0;
        if (dp[i][holding][k] != -1) return dp[i][holding][k];

        int ans = rec(k, prices, i + 1, holding, dp); 
        if (holding) {
            ans = max(ans, rec(k - 1, prices, i + 1, false, dp) + prices[i]);
        } else {
            ans = max(ans, rec(k, prices, i + 1, true, dp) - prices[i]);
        }
        
        return dp[i][holding][k] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return rec(k, prices, 0, false, dp);
    }
};
