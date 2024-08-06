class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> q; 
        int ans = INT_MIN; 
        
        for (int i = 0; i < points.size(); ++i) {
            while (!q.empty() && points[i][0] - points[q.front()][0] > k) {
                q.pop_front();
            }
            if (!q.empty()) {
                ans = max(ans, points[i][0] + points[i][1] + points[q.front()][1] - points[q.front()][0]);
            }
            
            while (!q.empty() && points[i][1] - points[i][0] >= points[q.back()][1] - points[q.back()][0]) {
                q.pop_back();
            }
    
            q.push_back(i);
        }
        
        return ans;
    }
};
