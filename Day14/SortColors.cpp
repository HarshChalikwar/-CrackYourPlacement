class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int k = nums.size()-1;
        while(j<=k)
        {
            while(i<nums.size() and nums[i] == 0){
                i++;
                j++;
            }
            while(j<nums.size() and nums[j] == 1)
            {
                j++;
            }
            while(k>=0 and nums[k] == 2)
            {
                k--;
            }
            if(j>k) break;
            if(nums[j] == 0)
            {
                swap(nums[i],nums[j]);
                continue;
            }
            if(nums[k] == 0)
            {
                swap(nums[j],nums[k]);
                swap(nums[i],nums[j]);
                continue;
            }
            if(nums[k] == 1)
            {
                swap(nums[j],nums[k]);
                continue;
            }
        }      
    }
};