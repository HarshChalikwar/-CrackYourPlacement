class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++)
        {
            if(i != 0 and nums[i] == nums[i-1]) continue;
            int l = i+1; 
            int h = nums.size()-1;
            while(l<h)
            {
                int sum = nums[i] + nums[l] + nums[h];

                if (sum == 0) {
                    v.push_back({nums[i], nums[l], nums[h]});
                    
                    // Skip duplicates for the second and third elements
                    while (l < h && nums[l] == nums[l + 1]) ++l;
                    while (l < h && nums[h] == nums[h - 1]) --h;
                    
                    ++l;
                    --h;
                } else if (sum < 0) {
                    ++l; // Increase sum by moving left pointer to the right
                } else {
                    --h; // Decrease sum by moving right pointer to the left
                }
            }
        }
        return v;
    }
};