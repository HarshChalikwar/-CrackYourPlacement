class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int cnt = 0;
        int sum = 0;
        m[0] = 1;
        for(int i = 0;i<nums.size();i++)
        {
            int cnt_i = cnt;
            sum += nums[i];
            cnt += m[sum%k];
            cnt += m[sum%k - k];
            cnt += m[sum%k + k];
            m[sum%k]++;
        }
        return cnt;
    }
};