#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int>input;
    stack<int>output;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        
        if(!output.empty()){
            int x=output.top();
            output.pop();
            return x;
        }else{
            if(input.empty()) return-1;
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int x=output.top();
            output.pop();
            return x;
        }
    }

    int peek() {
        // Implement the peek() function here.
        if (!output.empty()) {
          int x = output.top();
          return x;
        } else {
            if(input.empty()) return -1;
          while (!input.empty()) {
            output.push(input.top());
            input.pop();
          }
          int x = output.top();
          return x;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (input.empty() && output.empty());
    }
};