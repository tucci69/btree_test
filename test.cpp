#include "btree.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;
int main(){
  btree bt;
  for(int i=0;i<=10;i++) bt[rand()]=1;
  bt.print_sort();
}
