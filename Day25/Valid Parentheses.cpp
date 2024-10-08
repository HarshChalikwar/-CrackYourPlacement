class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(') s1.push('(');
            if(s[i] == '{') s1.push('{');
            if(s[i] == '[') s1.push('[');
            if(s[i] == ')'){
                if(s1.empty()) return false;
                if(s1.top() == '(') s1.pop();
                else return false;
            }
            if(s[i] == '}'){
                if(s1.empty()) return false;
                if(s1.top() == '{') s1.pop();
                else return false;
            }
            if(s[i] == ']'){
                if(s1.empty()) return false;
                if(s1.top() == '[') s1.pop();
                else return false;
            }
        }
        if(s1.size()!= 0) return false;
        return true;
    }
};