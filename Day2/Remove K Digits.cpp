class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int K = k;
        for(int i = 0;i<num.size();i++)
        {
            while(!st.empty() and st.top() > num[i] and k>0) {st.pop();k--;}
            st.push(num[i]);
        }
        cout<<st.size();
        while(st.size() > (num.size() - K))
        {
            st.pop();
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        bool t = true;
        string ans2 = ""; 
        for(auto i: ans )
        {
            if(t and i == '0')
            {
                continue;
            }
            else
            {   
                t = false;
                ans2 += i;
            }
        }
        if(ans2.size() == 0) return "0";
        return ans2;
    }
};