class Solution {
public:
    int MOD = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> nse(n),pse(n);
        stack<long long> s;
        for(long long i = 0;i<arr.size();i++)
        {
            while(!s.empty() and arr[s.top()] > arr[i])
            {
                s.pop();
            }
            long long j = -1;
            if(!s.empty()) j = s.top();
            pse[i] = j;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(long long i = n-1;i>=0;i--)
        {
            while(!s.empty() and arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            long long j = n;
            if(!s.empty()) j = s.top();
            nse[i] = j;
            s.push(i);
        }
        long long ans = 0;
        for(long long i = 0;i<n;i++)
        {
            ans += ((nse[i] - i)*(i - pse[i])*arr[i])%MOD;
        }
        return ans%MOD;
    }
};