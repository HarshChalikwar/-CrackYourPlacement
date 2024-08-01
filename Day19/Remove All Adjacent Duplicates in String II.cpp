class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0;i<s.size();i++)
        {
            if(!st.empty())
            {
                if (!st.empty() && st.top().first == s[i]) {
                    auto p = st.top();
                    st.pop();
                    st.push({p.first, p.second + 1});
                    if (st.top().second == k) st.pop();
                }
                else st.push({s[i],1});
            }
            else st.push({s[i],1});
        }
        string p = "";
        while(!st.empty())
        {
            p.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(p.begin(),p.end());
        return p;
    }
};