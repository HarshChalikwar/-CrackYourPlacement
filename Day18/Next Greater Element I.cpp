class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums2.size();i++)
        {
            m[nums2[i]] = i;
        }
        vector<int> nge(nums2.size());
        stack<int> st;
        for(int i = nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() and nums2[i] > st.top())
            {
                st.pop();
            }
            nge[i] = -1;
            if(!st.empty()) nge[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i = 0;i<nums1.size();i++)
        {
            ans.push_back(nge[m[nums1[i]]]);
        }
        return ans;
    }
};