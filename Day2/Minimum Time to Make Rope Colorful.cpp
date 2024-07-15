class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int i = 0;
        while(i<colors.size())
        {
            priority_queue<int,vector<int>,greater<int>> q;
            while(i<colors.size()-1 and colors[i] == colors[i+1])
            {
                q.push(neededTime[i]);
                i++;
            }
            q.push(neededTime[i]);
            while(q.size() != 1)
            {
                ans += q.top();
                q.pop();
            }
            i++;
        }
        return ans;
    }
};