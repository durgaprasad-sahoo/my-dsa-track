class MyQueue {
public:
    stack<int>input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }

    int pop() {
        int ans=-1;
        if(! output.empty()){
            ans = output.top();
            output.pop();
        }else{ // if output is empty, get all elements from input to output first
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            ans = output.top();
            output.pop();
            
        }return ans;
    }
    
    int peek() {
        if(! output.empty()){
            return output.top();
        }else{ // if output is empty, get all elements from input to output first
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            
        }return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
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
