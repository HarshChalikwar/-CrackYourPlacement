class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;int j = 0;
        while(i<nums.size() and j<nums.size())
        {
            if(nums[i] != 0) {i++;continue;}
            if(nums[j] == 0 or j<i) { j++;continue;}
            swap(nums[i],nums[j]);
        }      
    }
};