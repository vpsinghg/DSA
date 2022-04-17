/*
    Problem Title- Min Stack
    Platform - InterviewBit
    Problem Link - https://www.interviewbit.com/problems/min-stack/
    Concept - Stack and Queue 
    Asked In:
        YAHOO
        AMAZON
        ADOBE
        MICROSOFT
        GRAB
        TWITTER
    
    Difficulty Level - Medium

    Problem Description-  
        Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
        push(x) – Push element x onto stack.
        pop() – Removes the element on top of the stack.
        top() – Get the top element.
        getMin() – Retrieve the minimum element in the stack.
        Note that all the operations have to be constant time operations.

        Questions to ask the interviewer :

        Q: What should getMin() do on empty stack? 
        A: In this case, return -1.

        Q: What should pop do on empty stack? 
        A: In this case, nothing. 

        Q: What should top() do on empty stack?
        A: In this case, return -1


*/ 

/* 
    Solution Blog exists on
    HashNode - https://vikramsinghgurjar.hashnode.dev/min-stack-interview-bit-solution-problem-is-based-on-stack-data-structure#heading-optimised-solution
    Dev - https://dev.to/vpsinghg/min-stack-interviewbit-problem-1dg2
*/

stack<int> s;
int mini;
MinStack::MinStack() {
    s = stack<int>();
}

void MinStack::push(int x) {
    if(s.empty()){
        mini = x;
    }
    if(x>=mini){
        s.push(x);
    }
    else{
        s.push(2*x-mini);
        mini = x;
    }
}

void MinStack::pop() {
    if(s.empty()){
        return;
    }
    if(s.top()<mini){
        mini = 2*mini - s.top();
    }
    s.pop();
}

int MinStack::top() {
    if(s.empty()) {
        return -1;
    }
    

    if(s.top() >=mini){
        return s.top();
    }
    else{
        return mini;
    }
}

int MinStack::getMin() {
    if(s.empty()){
        return -1;
    }
    return mini;
}

