#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	vector<int>ans;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	priority_queue<pair<int,pair<int,int>>>pq;
	pq.push({a[n-1]+b[n-1],{n-1,n-1}});
	set<pair<int,int>>st;
	st.insert({n-1,n-1});
	while(k--){
		pair<int,pair<int,int>>top=pq.top();
		pq.pop();
		int sum=top.first;
		int x=top.second.first;
		int y=top.second.second;
		ans.push_back(sum);
		if(st.count({x-1,y})==0){
			pq.push({a[x-1]+b[y],{x-1,y}});
			st.insert({x-1,y});
		}
		if(st.count({x,y-1})==0){
			pq.push({a[x]+b[y-1],{x,y-1}});
			st.insert({x,y-1});
		}
	}
	return ans;
}