class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26);
        for(int i = 0;i<tasks.size();i++)
        {
            v[tasks[i]-'A']++;
        }
        priority_queue<int> q;
        for(auto i : v)
        {
            if(i != 0)
            {
            q.push(i);
            }
        }
        queue<pair<int,int>> p;
        int j = 0;
        while(j <= ((n+1)*tasks.size()))
        {
            if(q.empty() and p.empty()) return j;
            while(!p.empty() and p.front().second == j)
            {
                q.push(p.front().first);
                p.pop();
            }
            if(!q.empty())
            {
                if(q.top() > 1)
                {
                p.push({q.top()-1,j + n+1});
                }
                q.pop();
                
            }
            j++;
        }
        return j;
    }
};