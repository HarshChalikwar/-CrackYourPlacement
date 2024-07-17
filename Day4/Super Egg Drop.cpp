class Solution {
public:
    vector<vector<int>> dp;
    
    Solution() {
        dp.resize(10001, vector<int>(101, -1));
    }
    
    int superEggDrop(int k, int n) {
        if (n == 1 || n == 0) return n;
        if (k == 1) return n;
        if (dp[n][k] != -1) return dp[n][k];
        
        int low = 1, high = n, result = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int b = superEggDrop(k - 1, mid - 1);
            int n_b = superEggDrop(k, n - mid);
            int worst_case = max(b, n_b);
            
            if (b > n_b) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            
            result = min(result, worst_case + 1);
        }
        
        return dp[n][k] = result;
    }
};
