int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int c=0;
	for(int i=1;i<n;i++){
		if(arr[c]!=arr[i]){
			c++;
		}
		arr[c]=arr[i];
	}
	return c+1;
}