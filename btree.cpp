#include "btree.hpp"
#include <iostream>
#include <list>
#include <stack>

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
      return node->insert(key, mLeft);
    else 
      return mLeft = new Node(key);
  else
    if(mRight)
      return node->insert(key,mRight);
    else
      return mRight = new Node(key);
}

int& btree::operator[](const int& Key){
  if(root){
    Node* top=root;
    return top->insert(Key,top)->mValue;
  }
  else
    root = new Node(Key);
    return root->mValue;
}

#ifndef STACK

void btree::print_sort(){
  
  struct List{
    Node* node;
    List* lst;
    List(Node* nd, List* l) : node(nd),lst(l){};
  };
  
  List* lptr=0;
  List* tmp_lptr=0;
  Node* cnode=root;

  while(lptr or cnode){
    if(cnode){
      lptr = new List( cnode, lptr );
      cnode=cnode->mLeft;
    }
    else{
      cnode=lptr->node;
      tmp_lptr=lptr->lst;
      delete lptr;
      lptr=tmp_lptr;
      std::cout << cnode->mKey << std::endl;
      cnode=cnode->mRight;
    }
  }
}

#else

void btree::print_sort(){

  std::stack< Node* > st;
  Node* cnode=root;

  while( !st.empty() or cnode){
    if(cnode){
      st.push(cnode);
      cnode=cnode->mLeft;
    }
    else{
      cnode=st.top();
      st.pop();
      std::cout << cnode->mKey << std::endl;
      cnode=cnode->mRight;
    }
  }
}


#endif

























