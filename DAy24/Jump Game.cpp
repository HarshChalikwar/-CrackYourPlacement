class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sum = nums[0];
        for(int i  = 1 ;i<nums.size();i++)
        {       
            if(sum < i) return false;
            sum = max(sum,nums[i]+i);
        }        
        return true;
    }
};