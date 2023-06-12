#include<bits/stdc++.h>
string reverseString(string &str){
	// Write your code here.	
	stack<string>st;
	int n=str.size();
	if(n==0) return str;
	string ans;
	int i=0;
	for(int i=0;i<n;i++){
		string word;
		if(str[i]==' ')continue;
		while(i<n && str[i]!=' '){
			word+=str[i];
			i++;
		}
		st.push(word);
	}
	while(!st.empty()){
		ans+=st.top();
		st.pop();
		if(!st.empty()) ans+=" ";
	}
	return ans;
}