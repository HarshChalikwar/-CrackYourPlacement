class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int x = -1;
        int s = q1.size();
        if(q1.empty()) return 0;
        while(s>1)
        {
            x = q1.front();
            q2.push(x);
            q1.pop();
            s--;
        }
        x = q1.front();
        q1.pop();
        queue<int> q3;
        q3 = q1;
        q1 = q2;
        q2 = q3;
        return x;
    }
    
    int top() {
        int x = -1;
        while(!q1.empty())
        {
            x = q1.front();
            q2.push(x);
            q1.pop();
        }
        queue<int> q3;
        q3 = q1;
        q1 = q2;
        q2 = q3;
        return x;
    }
    bool empty() {
     if(q1.empty()) return true;
     return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */