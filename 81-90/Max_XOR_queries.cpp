#include <bits/stdc++.h> 
struct Node{
    Node*links[2];
    bool containsKey(int ind){
        return (links[ind]!=NULL);
    }
    Node*get(int ind){
        return links[ind];
    }
    void put(int ind,Node*node){
        links[ind]=node;
    }
};
class Trie{
    private:
    Node*root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node*node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getmax(int num){
        int maxsum=0;
        Node*node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(node->containsKey(!bit)){
                maxsum=maxsum | (1<<i);
                node=node->get(!bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxsum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	Trie trie;
	sort(arr.begin(),arr.end());
	vector<pair<int,pair<int,int>>>oq;
	int q=queries.size();
	for(int i=0;i<q;i++){
		oq.push_back({queries[i][1],{queries[i][0],i}});
	}
	sort(oq.begin(),oq.end());
	vector<int>ans(q,0);
	int ind=0;
	int n=arr.size();
	for(int i=0;i<q;i++){
		int ai=oq[i].first;
		int xi=oq[i].second.first;
		int qind=oq[i].second.second;
		while(ind<n &&arr[ind]<=ai){
			trie.insert(arr[ind]);
            ind++;
		}
        if(ind==0) ans[qind]=-1;
        else ans[qind]=trie.getmax(xi);
	}
    return ans;
}