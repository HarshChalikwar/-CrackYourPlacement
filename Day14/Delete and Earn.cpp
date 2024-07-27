class Solution {
public:
    int rec(int i,vector<int>& nums,vector<int>& dp,int max1)
    {
        if(i > max1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        
        ans = max(ans,rec(i+2,nums,dp,max1)+nums[i]*i);
        ans = max(ans,rec(i+1,nums,dp,max1));
        return dp[i] = ans;
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> nums2(1e4+1,0);
        int max = 0;
        for(int i = 0;i<nums.size();i++)
        {
            nums2[nums[i]]++;
            if(nums[i] > max) max = nums[i];
        }
        vector<int> dp(nums2.size(),-1);
        return rec(0,nums2,dp,max);
    }
};