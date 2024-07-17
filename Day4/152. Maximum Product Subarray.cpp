class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans = -1e10;
        long long pre = 1;
        for(int i = 0;i<nums.size();i++)
        {
            pre = pre*nums[i];
            if(pre <= -1e10) pre = -1e10;
            ans = max(ans,pre);
            if(pre == 0) pre = 1;
        }
        pre = 1;
        for(int i = nums.size()-1;i>0;i--)
        {
            pre = pre*nums[i];
            if(pre <= -1e10) pre = -1e10;
            ans = max(ans,pre);
            if(pre == 0) pre = 1;
        }
        return (int)ans;
    }
};