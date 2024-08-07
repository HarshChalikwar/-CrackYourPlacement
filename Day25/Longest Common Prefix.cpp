class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size1 = 0;
        for(int i = 0;i<strs[0].size();i++)
        {
            for(int j = 0;j<strs.size();j++)
            {
                if(strs[j].length()-1<i){
                    string ret;
                    for(int k = 0;k<size1;k++)
                    {
                        ret.push_back(strs[0][k]);
                    }
                    return ret;
                }
                else if(strs[j][i] != strs[0][i]) {
                    string ret;
                    for(int k = 0;k<size1;k++)
                    {
                        ret.push_back(strs[0][k]);
                    }
                    return ret;
                }
            }
            size1++;
        }   
                    string ret;
                    for(int k = 0;k<size1;k++)
                    {
                        ret.push_back(strs[0][k]);
                    }
                    return ret;
            
    }
};