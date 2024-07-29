class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> nums2;
        nums2.push_back(1);
        for(auto i: nums) nums2.push_back(i);
        nums2.push_back(1);
        vector<vector<int>> dp(nums.size() + 2,vector<int>(nums.size() + 2,0));
        for(int i = nums2.size()-2;i>=1;i--)
        {
            for(int j = i;j<=nums2.size()-2;j++)
            {
                for(int k = i;k<=j;k++)
                dp[i][j] = max(dp[i][j],dp[i][k-1] + dp[k+1][j] + nums2[i-1]*nums2[j+1]*nums2[k]);
            }
        }
        return dp[1][nums2.size()-2];
    }
};