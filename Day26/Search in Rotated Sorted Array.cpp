class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        int m;
        while(i<=j)
        {
            m = i + (j-i)/2;
            int mid = m;
            if(nums[m] == target) return m;
            else if(nums[m] >= nums[0] and target < nums[0])
            {
                i = mid + 1;
            }
            else if(nums[m] >= nums[0] and target >= nums[0])
            {
                if(nums[m] > target)
                {
                    j = mid-1;
                }
                else
                {
                    i = mid + 1;
                }
            }
            else if(nums[m] <= nums[nums.size()-1] and target <= nums[nums.size()-1])
            {
                if(target > nums[m])
                {
                    i = m+1;
                }
                else
                {   
                    j  = m-1;
                }
            }
            else 
            {
                j = m -1; 
            }
        }
        return -1;
    }
};