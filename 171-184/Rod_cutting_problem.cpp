int help(int ind,int w,vector<int>&weight,vector<int>&price,int n,vector<vector<int>>&dp){
	if(ind ==0) return w*price[0];
	if(dp[ind][w]!=-1) return dp[ind][w];
	int ntake=help(ind-1,w,weight,price,n,dp);
	int take=INT_MIN;
	if(weight[ind]<=w){
		take=price[ind]+help(ind,w-weight[ind],weight,price,n,dp);
	}
	return dp[ind][w]=max(take,ntake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int>weight(n+1);
	for(int i=0;i<n;i++){
		weight[i]=i+1;

	}
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	return help(n-1,n,weight,price,n,dp);
}
