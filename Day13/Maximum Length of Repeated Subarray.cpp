class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),0));
        int ans = 0;
        for(int i = 0;i<dp.size();i++)
        {
            for(int j = 0;j<dp[0].size();j++)
            {
                if(i == 0 or j == 0)
                {
                    if(nums1[i] == nums2[j]) dp[i][j] = 1;
                }
                else 
                {
                    if(nums1[i] == nums2[j]) dp[i][j] = dp[i-1][j-1]+1;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};