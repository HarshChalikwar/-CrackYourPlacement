class Solution {
public:
    static bool comp(int a,int b)
    {
        if(a > b) return true;
        return false;
    }
    int minDeletions(string s) {
        map<int,char> m1;
        unordered_map<char,int> m2;
        for(int i = 0;i<s.size();i++)
        {
            m2[s[i]]++;
        }
        vector<int> v;
        for(auto i: m2)
        {
            v.push_back(i.second);
        }
        sort(v.begin(),v.end(),comp);
        int cnt = 0;
        int prev_cnt = 1e9;
        for(auto i: v)
        {
            if(i < prev_cnt){
                prev_cnt = i;
            }
            else
            {
                    cnt = cnt + (i-prev_cnt)+1;
                    if(prev_cnt > 1)
                    prev_cnt = prev_cnt - 1;
            }
        }
        return cnt;
    }
};