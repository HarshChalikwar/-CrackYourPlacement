class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> v;
        for(int i = 0;i<intervals.size();i++)
        {
            v.push_back({intervals[i][1],intervals[i][0]});
        }
        sort(v.begin(),v.end());
        int end = v[0].first;
        int cnt = 0;
        for(int i = 1;i<v.size();i++)
        {
            if(v[i].second < end)
            {
                cnt++;
            }
            else
            {
                end = v[i].first; 
            }
        }
        return cnt;
    }
};