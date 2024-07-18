class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> m;
        for(int i = 0;i<wordList.size();i++)
        {
            m[wordList[i]]++;
        }
        vector<string> v;
        if(m.find(endWord) == m.end()) return 0;
        for(auto i: m)
        {
            v.push_back(i.first);
        }
        for(int i = 0;i<v.size();i++)
        {
            m[v[i]] = 0;
        }
        queue<string> q;
        q.push(beginWord);
        int cnt = 0;
        m[beginWord] = 1;
        while(!q.empty())
        {
            cnt++;
            int s = q.size();
                    while(s)
                    {
                        string h = q.front();
                        q.pop();
                        if(h == endWord) return cnt;

                        for(int i = 0;i<h.size();i++)
                        {
                            char original = h[i];
                            for(char c = 'a';c<='z';c++)
                            {
                                h[i] = c;
                                if(m.find(h) != m.end() and m[h] == 0)
                                {
                                    m[h] = 1;
                                    q.push(h);
                                }
                            }
                            h[i] = original;
                        }
                        s--;
                    }
    } 
        return 0;
    }
};