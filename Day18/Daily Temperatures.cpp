class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nge(temperatures.size(),0);
        stack<int> st;
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            while(!st.empty() and temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            if(!st.empty()) nge[i] = st.top()- i;
            st.push(i);
        }
        return nge;
    }
};