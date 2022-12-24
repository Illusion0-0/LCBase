class MyQueue {
public:
    stack<int>s1,s2;
    int sz=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        sz++;
    }
    
    int pop() {
        sz--;
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        int k = s2.top();
        s2.pop();
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        return k;
    }
    
    int peek() {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        int k = s2.top();
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        return k;
    }
    
    bool empty() {
        return sz?false:true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */