#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	int ans=-1;
	map<int,int>m;
	for(int i=0;i<n;i++){
		m[arr[i]]++;
	}
	for(auto i:m){
		if(i.second>1){
			ans=i.first;
		}
	}
	return ans;
}
