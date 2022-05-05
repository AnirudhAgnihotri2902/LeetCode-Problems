class MyStack {
public:
    stack<int>stack;
    MyStack() {
        
    }
    
    void push(int x) {
        stack.push(x);
    }
    
    int pop() {
        int temp= stack.top();
        stack.pop();
        return temp;
        
    }
    
    int top() {
        return stack.top();
        
    }
    
    bool empty() {
        return stack.empty();
        
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