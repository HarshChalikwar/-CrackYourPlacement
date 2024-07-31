class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "",t1 = "";
        deque<char> st;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '#')
            {
                if(!st.empty()) st.pop_back();
            }
            else st.push_back(s[i]);
        }
        while(!st.empty()) {s1.push_back(st.front());st.pop_front();}
        for(int i = 0;i<t.size();i++)
        {
            if(t[i] == '#')
            {
                if(!st.empty()) st.pop_back();
            }
            else st.push_back(t[i]);
        }
        while(!st.empty()) {t1.push_back(st.front());st.pop_front();}
        return (s1 == t1);
    }
};