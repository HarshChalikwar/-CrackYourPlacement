class Solution {
public:
    int rec(vector<int>& nums,int i,int prev,vector<vector<int>>& dp)
    {
        if(i == nums.size()) return 0;
        if(prev!= -1 and dp[i][prev] != -1) return dp[i][prev];
        int ans = 0;
        if(prev != -1)
        {
            if(nums[i] > nums[prev])  ans = max(ans,rec(nums,i+1,i,dp)+1);
            ans = max(ans,rec(nums,i+1,prev,dp));
        }
        else
        {
            ans  = max(ans,rec(nums,i+1,prev,dp));
            ans  = max(ans,rec(nums,i+1,i,dp)+1);
            return ans;
        }
        return dp[i][prev] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return rec(nums,0,-1,dp);
    }
};