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
int maximumXor(vector<int> A)
{
    // Write your code here.  
    Trie trie;
    for(auto it:A){
        trie.insert(it);
    } 
    int maxi=-1;
    for(auto it:A) {
        maxi=max(maxi,trie.getmax(it));
    }
    return maxi;
}