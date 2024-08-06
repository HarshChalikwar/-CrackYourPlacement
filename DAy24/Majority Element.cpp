class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0;
        int cnt = 0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i] == major)
            {
                cnt++;
            }
            else if(cnt<=0) 
            {
                major = nums[i];
                cnt = 1;
            }
            else cnt--;
        }   
        return major;
    }
};