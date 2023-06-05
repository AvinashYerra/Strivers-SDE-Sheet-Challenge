#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	set<int>x,y;
	int n=matrix.size();
	int m=matrix[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				x.insert(i);
				y.insert(j);
			}
		}
	}
	for(auto row:x){
		for(int j=0;j<m;j++){
			if(matrix[row][j]!=0) matrix[row][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(auto col:y){
			if(matrix[i][col]!=0) matrix[i][col]=0;
		}
	}
	
}