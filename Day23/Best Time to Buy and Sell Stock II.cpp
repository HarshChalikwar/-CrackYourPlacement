class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prev(2,0);
        vector<int> cur(2,0);
        for(int i = prices.size()-1;i>=0;i--)
        {
            for(int j = 0;j<2;j++)
            {
                if(j == 0)
                {
                    cur[0] = max(prev[0],prev[1]-prices[i]);
                    prev[0] = cur[0];
                }
                else
                {
                    cur[1] = max(prev[1],prev[0]+prices[i]);
                    prev[1] = cur[1];
                }
            }
        }
       return prev[0]; 
    }
};
