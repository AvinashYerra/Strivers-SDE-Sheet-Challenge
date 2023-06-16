#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int maxi=INT_MIN;
	int pre=1;
	int suff=1;
	for(int i=0;i<n;i++){
		if(pre==0) pre=1;
		if(suff==0) suff=1;
		pre=pre*arr[i];
		suff=suff*arr[n-i-1];
		maxi=max(maxi,max(suff,pre));
	}
	return maxi;
}
