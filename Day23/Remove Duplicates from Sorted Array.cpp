class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        vector<int> expectedNums(nums.size(),0);
        for(int i = 0;i<nums.size();i++)
        {
            if(j == 0) {expectedNums[j]  = nums[i];j++;continue;cout<<expectedNums[j];}
            if(expectedNums[j-1]  == nums[i])  continue;
            else
            {
            expectedNums[j]  = nums[i];
            j++;
            }
        }
        for(int i = 0;i<nums.size();i++)
        {
            nums[i] = expectedNums[i];

        }
        return j;
    }
};