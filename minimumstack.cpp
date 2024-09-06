class MinStack {
public:
    stack<int> mainStack;
    stack<int> subStack;
    int currentMin;
     
    MinStack() {
        

    }
    
    void push(int val) {
        if(mainStack.empty()){
           this->currentMin = val;
            mainStack.push(val);
            subStack.push(val);
        }else{
            if(val<this->currentMin){
                this->currentMin = val;
                mainStack.push(val);
                subStack.push(val);
            }
            else{
                mainStack.push(val);
                subStack.push(subStack.top());
            }
        }

       
    }
    
    void pop() {
    if(!mainStack.empty()){
        mainStack.pop();
        cout<<subStack.top();
        subStack.pop();
        }
        
    }
    
    int top() {
        return mainStack.top();  
        
    }
    
    int getMin() {
        return subStack.top();
    }
};
