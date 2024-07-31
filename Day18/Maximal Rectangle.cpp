class Solution {
public:
    int lra(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();
        for(int i = 0;i<heights.size();i++)
        {
            while(!st.empty() and heights[st.top()] >= heights[i] )
            {
                int j = st.top();
                st.pop();
                int k =-1;
                if(!st.empty()) k =st.top();
                ans = max(ans,(i-k-1)*heights[j]);
            }
            int k =-1;
            if(!st.empty()) k =st.top();
            ans = max(ans,(i-k)*heights[i]);
            st.push(i);
        }
        while(!st.empty())
        {
            int i = st.top();
            st.pop();
            int k = -1;
            if(!st.empty()) k =st.top();
            ans = max(ans,(n-k-1)*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size(),0);
        int ans = 0;
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {   
                if(matrix[i][j] == '0') {dp[j] = 0;continue;}
                dp[j] = dp[j]+1;
            }
            ans = max(ans,lra(dp));
        }
        return ans;
    }
};