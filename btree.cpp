#include "btree.hpp"

struct btree::Node{
  int mKey;
  int mValue;
  Node* mLeft;
  Node* mRight;
  Node(int k) : mKey(k), mValue(0), mLeft(0), mRight(0) {}
  Node* insert(const int&, Node*); 
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

btree::Node* btree::Node::insert(const int& key, Node* node){
  if(key==mKey)
    return node;
  else if(key < mKey)
    if(mLeft) 
      return  insert(key, mLeft);
    else 
      return mLeft = new Node(key);
  else
    if(mRight)
      return insert(key,mRight);
    else
      return mRight = new Node(key);
}

int& btree::operator[](const int& Key){
  return root->insert(Key,root)->mValue;
}
