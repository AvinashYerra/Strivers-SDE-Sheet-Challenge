#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node*krev(Node*head,int i,int n,int b[]){
	if(head==NULL) return NULL;
	Node*prev=NULL;
	Node*curr=head;
	Node*next=NULL;
	int cnt=0;
	while(b[i]==0 && i<n){
		i++;
	}
	while(curr!=NULL && cnt<b[i] && i<n ){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		cnt++;
	}
	if(next!=NULL){
		i=i+1;
		if(i<n){
			head->next=krev(next,i,n,b);
		}else{
			head->next=next;
		}
	}
	return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(b[0]==0) return head;
	return  krev(head, 0,n,b);
	

}