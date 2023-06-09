#include <bits/stdc++.h> 
bool canplace(int dist,vector<int>&positions,int n,int c){
	int cor=positions[0];
	int cnt=1;
	for(int i=1;i<n;i++){
		if(positions[i]-cor>=dist){
			cnt++;
			cor=positions[i];
		}
		if(cnt==c) return true;
	}
	return false;
}
int chessTournament(vector<int> &positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int ans=-1;
	int low=1;
	int high=positions[n-1]-positions[0];
	while(low<=high){
		int mid=low+(high-low)/2;
		if(canplace(mid,positions,n,c)){
			ans=mid;
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	return ans;
}