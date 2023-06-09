#include <bits/stdc++.h> 
struct Node{
    Node*links[26];
    bool flag=false;
    bool contains(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
};
int distinctSubstring(string &word) {
    //  Write your code here.AC
    int cnt=0;
    Node*root=new Node();
    for(int i=0;i<word.size();i++){
        Node*node=root;
        for(int j=i;j<word.size();j++){
            if(!node->contains(word[j])){
                cnt++;
                node->put(word[j],new Node());
            }
            node=node->get(word[j]);
        }
    }
    return cnt;
}
