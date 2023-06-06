/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int len=0;
    Node*curr=head;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }
    curr=head;
    int x=len-K+1;
    if(x==1) return head->next;
    for (int i = 0; i < x - 2; i++) {
      curr = curr->next;
    }
    curr->next=curr->next->next;
    return head;

}
