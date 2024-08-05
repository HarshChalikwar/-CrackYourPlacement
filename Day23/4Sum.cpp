class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i = 0;i<nums.size();i++)
        {   
            if(i != 0 and nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<nums.size();j++)
            {
                if(j != i+1 and nums[j] == nums[j-1]) continue;
                long long sum = nums[i] + nums[j];
                int l = j+1;
                int h = nums.size()-1;
                while(l<h)
                {
                    if(sum + (long)nums[l] + (long)nums[h] == (long long)target) {v.push_back({nums[i],nums[j],nums[l],nums[h]});l++;while(nums[l] == nums[l-1] and l<h) l++;;h--;while(nums[h] == nums[h+1] and l<h) h--;}
                    else if(sum + (long)nums[l] + (long)nums[h] < (long long)target) {l++;while(nums[l] == nums[l-1] and l<h) l++;}
                    else {h--;while(nums[h] == nums[h+1] and l<h) h--;}
                }
            }
        }
        return v;
    }
};