#include <bits/stdc++.h> 
void insert(stack<int>&st,int temp){
	if(st.size()==0 || st.top()<=temp){
		st.push(temp);
		return;
	}
	int x=st.top();
	st.pop();
	insert(st,temp);
	st.push(x);
	return;
}
void sortStack(stack<int> &st)
{
	// Write your code here
	if(st.size()==0){
		return;

	}
	int temp=st.top();
	st.pop();
	sortStack(st);
	insert(st,temp);
	return;
}