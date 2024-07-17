class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i = 0;i<n+1;i++)
        {
            if(i == 0) ans[i] = 0;
            else if(i == 1) ans[i] = 1;
            else
            {
                int no = i;
                int no2 = (no & (no-1));
                ans[i] = ans[no2] + 1;
            }
        }
        return ans;
    }
};