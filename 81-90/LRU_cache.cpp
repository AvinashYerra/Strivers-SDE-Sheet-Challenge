#include<bits/stdc++.h>
class LRUCache
{
public:
class node{
    public:
    int key;
    int val;
    node*prev;
    node*next;
    node(int key,int val){
        this->key=key;
        this->val=val;
    }
};
 node*head=new node(-1,-1);
 node*tail=new node(-1,-1);
 int cap;
 unordered_map<int,node*>mp;

    LRUCache(int capacity)
    {
        // Write your code here
       this->cap=capacity;
       head->next=tail;
       tail->prev=head;
    }
    void addnode(node*currnode){
         currnode->next=head->next;
         head->next=currnode;
         currnode->next->prev=currnode;
         currnode->prev=head;


    }
    void deletenode(node*delnode){
        node*delnext=delnode->next;
        node*delprev=delnode->prev;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key)
    {
        // Write your code here
        if(mp.find(key)!=mp.end()){
            node*resnode=mp[key];
            int resval=resnode->val;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key]=head->next;
            return resval;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key)!=mp.end()){
            node*cur=mp[key];
            mp.erase(key);
            deletenode(cur);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};
