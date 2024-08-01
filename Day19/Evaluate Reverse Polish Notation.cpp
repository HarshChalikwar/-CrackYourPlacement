class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0;i<tokens.size();i++)
        {
            if(tokens[i] == "+")
            {
                int i  = s.top();
                s.pop();
                int j = s.top();
                s.pop();
                s.push(j+i);
            }
            else if(tokens[i] == "-")
            {
                int i  = s.top();
                s.pop();
                int j = s.top();
                s.pop();
                s.push(j-i);
            }
            else if(tokens[i] == "*")
            {
                int i  = s.top();
                s.pop();
                int j = s.top();
                s.pop();
                s.push(j*i);
            }
            else if(tokens[i] == "/")
            {
                int i  = s.top();
                s.pop();
                int j = s.top();
                s.pop();
                s.push(j/i);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};