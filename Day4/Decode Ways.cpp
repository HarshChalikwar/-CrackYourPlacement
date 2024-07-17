class Solution {
public:
    int func(string s, int i, vector<int>& memo) {
        if (i == -1) {
            return 1;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        
        int ways = 0;
        if (s[i] > '0') {
            ways = func(s, i - 1, memo);
        }
        if (i >= 1 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
            ways += func(s, i - 2, memo);
        }
        
        memo[i] = ways;
        return ways;
    }

    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        vector<int> memo(s.size(), -1);
        return func(s, s.size() - 1, memo);
    }
};