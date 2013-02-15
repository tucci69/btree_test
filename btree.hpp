/*Header file for btree*/

class btree{
  struct Node;
  Node* root;
public:
  btree() : root(0){}
  int& operator[](const int&);
  void print_sort();
};
