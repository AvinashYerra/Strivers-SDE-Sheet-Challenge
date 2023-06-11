#include <bits/stdc++.h> 
// Stack class.
class Stack {
private:
    int size;
    int *arr;
    int tail;
public:
    
    Stack(int capacity) {
        // Write your code here.
        tail=0;
        size=capacity;
        arr=new int[size];
    }

    void push(int num) {
        // Write your code here.
        if (tail != size) {
          arr[tail] = num;
          tail++;
        }
    }

    int pop() {
        // Write your code here.
       if(tail!=0){
           tail--;
           return arr[tail];
       }
       return -1;
       
    }
    
    int top() {
        // Write your code here.
        return (tail!=0) ? (arr[tail-1]) : (-1);
    }
    
    int isEmpty() {
        // Write your code here.
        return (tail==0) ?(1) : (0);
    }
    
    int isFull() {
        // Write your code here.
        return (tail==size);
    }
    
};