#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int cntEndwith=0;
    int cntPrefix=0;
    bool containkey(char ch){
        return (links[ch-'a']!=NULL );
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    void increaseEnd(){
        cntEndwith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndwith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndwith;
    }
    int getPrefix(){
        return cntPrefix;
    }
};
class Trie{
    private:
    Node*root;
    public:

    Trie(){
        // Write your code here.
    root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containkey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(node->containkey(word[i])){
                node=node->get(word[i]);
            }else{
                return 0;
            }
        }
       return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node*node=root;
         for(int i=0;i<word.size();i++){
            if(node->containkey(word[i])){
                node=node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(node->containkey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }else{
                return;
            }
        }
        node->deleteEnd(); 
    }
};
