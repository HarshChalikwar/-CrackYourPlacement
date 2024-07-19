class Solution {
public:
    int trap(vector<int>& height) {
        int max1 = 0;
        int cnt = 0;
        vector<int> nge(height.size());
        stack<int> st;
        int ma = 0;
        for(int i = height.size()-1;i>=0;i--)
        {
            if(height[i] > ma) ma = height[i];
            nge[i] = ma;
        }
        // for(int i = 0;i<nge.size();i++) cout<<nge[i];
        for(int i = 0;i<height.size();i++)
        {
            if(height[i] >= height[max1]) 
            {
                max1 = i;
            }
            else
            {
                cnt += max(0   ,  (min(height[max1],nge[i]) - height[i])  );
            }
        }
        return cnt;
    }
};