class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>  prefix(nums.size());
        unordered_map<int,int> m;
        int cnt = 0;
        int sum = 0;
        m[0]++;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            if(m.find(sum-k) != m.end()){
                cnt = cnt + m[sum-k];
            }
            m[sum]++;
        }
        return cnt;
    }
};