class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int f = nums[0];
        int s = nums[0];
        while(1)
        {
            f = nums[nums[f]];
            s = nums[s];
            if(f == s) break;
        }
        f = nums[0];
        while(1)
        {
            if(f == s) break;
            f = nums[f];
            s = nums[s];
        }
        return f;
    }
};