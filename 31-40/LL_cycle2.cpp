/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
    bool check=false;
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if (slow == fast) {
          check = true;
          break;
        }
    }
    slow=head;

    if(check){
       while(fast!=NULL && fast->next!=NULL){
           if(slow==fast){
               return slow;
           }
           slow=slow->next;
           fast=fast->next;
           
       }
    }
    return false;

}