class StockSpanner {
public:
    vector<int> v;
    stack<int> s;
    int index;
    StockSpanner() {
        index = 0;
    }
    int next(int price) {
        int span;
        v.push_back(price);
        while(!s.empty() and v[s.top()] <= price) s.pop();
        if(s.empty()) span = index+1;
        else span = index-s.top();
        s.push(index);
        index++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */