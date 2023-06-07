/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     int len=0;
     Node*curr=head;
     while(curr!=NULL){
          len++;
          curr=curr->next;
          
     }
     k=k%len;
     curr=head;
     while(curr->next!=NULL){
          curr=curr->next;
     }
     curr->next=head;
     int x=len-k;
     curr=head;
     for(int i=0;i<x-1;i++){
          curr=curr->next;
     }
     head=curr->next;
     curr->next=NULL;
     return head;

}