class Solution {
public:
    int dp[35][35];
    int rec(int i,int j,vector<int>& stones,int k,vector<int>& sum)
    { 
        if(j - i <= k - 2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int start = i;start<j;start += k-1)
        {
            int left = rec(i,start,stones,k,sum);
            int right = rec(start+1,j,stones,k,sum);
            mini = min(mini,left+right);
        }
        if((j-i) % (k-1) == 0)
        {
            int s = 0;
            s += sum[j];
            if(i>0)
            {
                s -= sum[i-1];
            }
            mini += s;
        }
        return dp[i][j] = mini;
    }
    int mergeStones(vector<int>& stones, int k) 
    {
        int N = stones.size();
      if ((N-1)%(k-1) > 0) return -1;
        vector<int> sum(stones.size(),0);
        sum[0] = stones[0];
        for(int i = 1;i<stones.size();i++)
        {
            sum[i] = sum[i-1] + stones[i];
        }
        memset(dp,-1,sizeof(dp));
        return rec(0,stones.size()-1,stones,k,sum);
    }
};