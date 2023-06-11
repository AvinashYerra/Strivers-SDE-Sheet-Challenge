#include <bits/stdc++.h> 
class Queue {
    int*arr;
    int qfront;
    int qrear;
    int size;
public:
    Queue() {
        // Implement the Constructor
        size=1000;
        arr=new int[size];
        qfront=0;
        qrear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront==qrear){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(qrear==size){
            return;
        }
        else{
            arr[qrear]=data;
            qrear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qrear==qfront){
            return -1;
        }else{
            int x=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==qrear){
                qfront=0;
                qrear=0;
            }
            return x;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront==qrear){
            return -1;
        }
        return arr[qfront];
    }
};