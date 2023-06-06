#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int rep=0;
	int s=0;
	map<int,int>mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
		s+=arr[i];
	}
	for(auto i:mp){
		if(i.second>1){
			rep=i.first;
		}
	}
	s-=rep;
	int x=n*(n+1)/2;
	int mis=x-s;
	return{mis,rep};
}
