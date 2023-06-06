/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node*ans=new Node(0);
    Node*temp=ans;
    int carry=0;
    while(num1||num2||carry){
        int a=0,b=0;
        if(num1){
            a=num1->data;
            num1=num1->next;
        }
        if(num2){
            b=num2->data;
            num2=num2->next;
        }
        int sum=a+b+carry;
        carry=sum/10;
        Node*newNode=new Node(sum%10);
        temp->next=newNode;
        temp=temp->next;
    }
    return ans->next;
}
