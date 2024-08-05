class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       vector<int> pre(cardPoints.size()),post(cardPoints.size());
       int sum = 0;
       for(int i = 0;i<cardPoints.size();i++)
       {
            sum += cardPoints[i];
            pre[i] = sum;
       }
       sum = 0;
       for(int i = cardPoints.size()-1;i>=0;i--)
       {
            sum += cardPoints[i];
            post[i] = sum;
       }
       int ans = 0;
       int n = cardPoints.size();
       for(int i = -1;i<k;i++)
       {
            if(i == -1)
            ans = max(ans,post[n-k+i+1]);
            else if(i == k-1)
            {
                ans = max(ans,pre[k-1]);
            }
            else
            ans = max(ans,pre[i] + post[n-k+i+1]);
       }
       return ans;
    }
};