class Solution {
public:
    bool rec(string& s,int i,int j,int chance)
    {
        if(i>=j) return true;
        bool ans = false;
        if(s[i] == s[j])
        {
            ans = ans or rec(s,i+1,j-1,chance);
        }
        else
        {
            if(chance)
            {
                ans = ans or rec(s,i+1,j,0);       
                ans = ans or rec(s,i,j-1,0);
            }
            else return false;
        }
        return ans;
    }
    bool validPalindrome(string s) {
        return rec(s,0,s.size()-1,1);
    }
};