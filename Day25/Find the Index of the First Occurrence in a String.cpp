class Solution {
public:
    int strStr(string haystack, string needle) {
       vector<int> lsp(needle.size());
       lsp[0] = 0;
       int prev  = 0;int i = 1;
       while(i<needle.size())
       {
            if(needle[i] == needle[prev])
            {
                lsp[i] = prev + 1;
                prev++;
                i++;
            }
            else
            {
                if(prev == 0)
                {
                    lsp[i] = 0;
                    i++;
                }
                else
                {
                    prev = lsp[prev-1];
                }
            }
       }
       for(auto c: lsp)
       {
            cout<<c;
       }
       int j = 0;
       i = 0;
       while(i<haystack.size())
       {
            if(needle[j] == haystack[i])
            {
                i++;j++;
            }
            else 
            {
                if(j == 0)
                {
                    i++;
                }
                else
                {
                    j = lsp[j-1];
                }
            }
            if(j == needle.size()) return i - needle.size();
       }
       return -1;
    }
};