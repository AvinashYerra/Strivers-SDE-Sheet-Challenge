LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int>*ans;
    bool f=1;
    while(head!=NULL){
        LinkedListNode<int>*temp=new LinkedListNode<int>(head->data);
        if(f) ans=temp,f=0;
        temp->next=head->next;
        temp->random=head->random;
        head=head->next;
        temp=temp->next
    }
    return ans;
}