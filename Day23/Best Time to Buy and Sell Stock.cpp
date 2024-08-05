class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices[0]; 
        int max1 = 0;
        for(int i = 0;i<prices.size();i++)
        {
           if(prices[i] >= l) {max1 = max(max1,prices[i]-l);continue;}
           else if(prices[i] < l) l = prices[i];
        }
        return max1;
    }
};