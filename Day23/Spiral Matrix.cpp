class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        int i = 0;
        int j = 0;
        int s1 = -1;
        int s2 = 0;
        vector<int> v;
        while(1)
        {
            while(i<n-1)
            {
                v.push_back(matrix[j][i]);
                i++;
            }
            n--;
            if(s1 == n) {v.push_back(matrix[j][i]);break;}
            while(j<m-1)
            {
                v.push_back(matrix[j][i]);
                j++;
            }
            m--;
            if(s2 == m) {v.push_back(matrix[j][i]);break;}
            while(i>s1+1)
            {
                v.push_back(matrix[j][i]);
                i--;
            }
            s1++;
             if(s1 == n) {v.push_back(matrix[j][i]);break;}
            while(j>s2+1)
            {
                v.push_back(matrix[j][i]);
                j--;
            }
            s2++;
            if(s2 == m) {v.push_back(matrix[j][i]);break;}
        }
        return v;
    }
};