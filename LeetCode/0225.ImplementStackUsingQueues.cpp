#include <queue>

class MyStack {
public:
    std::queue<int> container;

    MyStack() {
        
    }
    
    void push(int x) {
        container.push(x);
    }
    
    int pop() {
        int output = 0;
        
        int sz = container.size();
        for (int i = 0; i < sz - 1; i++)
        {
            container.push(container.front());
            container.pop();
        }
        output = container.front();
        container.pop();
        
        return output;
    }
    
    int top() {
        int output = 0;
        
        int sz = container.size();
        for (int i = 0; i < sz; i++)
        {
            output = container.front();
            container.push(output);
            container.pop();
        }
        
        return output;
    }
    
    bool empty() {
        return container.empty();
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