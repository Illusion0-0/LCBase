class MyStack {
public:
    queue<int>q;
    int sz=0;
    MyStack() {
       sz=0; 
    }
    
    void push(int x) {
        q.push(x);
        sz++;
        for(int i=0;i<sz-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int k = q.front();
        if(!q.empty())q.pop(),sz--;
        return k;
    }
    
    int top() {
        if(!q.empty())return q.front();
        else return -1;
    }
    
    bool empty() {
        return !sz?true:false;
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