/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include<bits/stdc++.h>
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	vector<int>v;
	Node*curr=head;
	while(curr!=NULL){
		Node*temp=curr;
		while(temp!=NULL){
			v.push_back(temp->data);
			temp=temp->child;
		}
		curr=curr->next;
	}
	sort(v.begin(),v.end());
	Node*he=new Node(0);
	Node*temp1=he;
	for(int i=0;i<v.size();i++){
		Node*x=new Node(v[i]);
		temp1->child=x;
		temp1=temp1->child;
	}
	temp1->child=NULL;
	return he->child;
}
