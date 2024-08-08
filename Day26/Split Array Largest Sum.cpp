class Solution {
public:
    bool isPossible(vector<int>& nums,int k,int mid)
    {
        int cnt = 1;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(sum + nums[i] > mid)
            {
                sum = nums[i];
                cnt++;
            }
            else sum+= nums[i];
        }
        if(cnt <= k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0;
        int h = INT_MAX;
        int result = 0;
        for(int i = 0;i<nums.size();i++)
        {
            l = max(nums[i],l);
        }
        while(l<h)
        {
            int mid = l + (h-l)/2;
            if(isPossible(nums,k,mid))
            {
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};