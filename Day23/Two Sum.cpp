class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> v;
        for(int i = 0;i< nums.size();i++){
            if(m.find(nums[i]) != m.end())
            {
                v.push_back(m[nums[i]]);
                v.push_back(i);
            }
            else
            {
                m.insert({target-nums[i],i});
            }
        }   
        return v;
    }
};