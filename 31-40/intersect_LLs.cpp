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

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node*curr=firstHead;
    while(curr!=NULL){
        curr->data=5000-(curr->data);
        curr=curr->next;
    }
    curr=secondHead;
    while(curr!=NULL){
        if(curr-data>4000){
          curr->data=5000-curr->data;
          return curr;
        }
        curr=curr->next;
    }
    return 0;
}