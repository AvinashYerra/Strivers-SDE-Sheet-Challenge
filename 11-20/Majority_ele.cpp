#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int cnt=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if(cnt==0){
			cnt=1;
			ans=arr[i];
			continue;
		}
		if(arr[i]==ans){
			cnt++;
		}else{
			cnt--;
		}
	}
	int x=0;
	for(int i=0;i<n;i++){
       if(arr[i]==ans){
		   x++;
	   }
	}
	if(x>n/2) return ans;
	return -1;
}