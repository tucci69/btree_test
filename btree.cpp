#include "btree.hpp"

struct btree::Node{
  int mKey;
  int mValue;
  Node* mLeft;
  Node* mRight;
  Node(int k,int v) : mKey(k), mValue(v), mLeft(0), mRight(0) {}
  void insert(int,int,Node*); 
  Node* find(int,Node*);
};



btree::Node* btree::Node::find(int key, Node* node){
  if(key == mKey) 
    return node;
  else if(key < mKey){
    if(!mLeft) return 0;
    return find(key,mLeft);
  }
  else{
    if(!mRight) return 0;
    return find(key,mRight);
  }
}

void btree::Node::insert(int key, int value, Node* node){
  if(key==mKey)
    mValue=value;
  else if(key < mKey)
    if(mLeft) 
      insert(key,value,mLeft);
    else 
      mLeft = new Node(key,value);
  else
    if(mRight)
      insert(key,value,mRight);
    else
      mRight = new Node(key,value);
}

int& btree::operator[](const int& Key){
  int Value;
  Node::insert(Key,Value,root);
}
