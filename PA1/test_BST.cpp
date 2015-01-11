#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/**
 * A simple test driver for the BST class template.
 * P1 CSE 100 2012
 * Author: P. Kube (c) 2012
 */
int main() {

  /* Create an STL vector of some ints */
  vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  v.push_back(100);
  v.push_back(-33);

  /* Create an instance of BST holding int */
  BST<int> b;

  /* Insert a few data items. */
  vector<int>::iterator vit = v.begin();
  vector<int>::iterator ven = v.end();
  cout << "Performing BST insertion test .... " << endl;
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return true
    if(! b.insert(*vit) ) {
      cout << "Incorrect return value when inserting " << *vit << endl;
      return -1;
    }
  }

  vit = v.begin();
  for(; vit != ven; ++vit) {
    // all these inserts are duplicates, so should return false
    if( b.insert(*vit) ) {
      cout << "Incorrect return value when re-inserting " << *vit << endl;
      return -1;
    }
  }
  cout << "Insertion test passed!" << endl;

  /* Test size. */
  cout << "Performing get size test ...." << endl;
  cout << "Size is: " << b.size() << endl;
  if(b.size() != v.size()) {
    cout << "... which is incorrect." << endl;
    return -1;
  }
  cout << "Get size test passed!" << endl;

  /* Test find return value. */
  cout << "Performing find item test ...." << endl;
  vit = v.begin();
  for(; vit != ven; ++vit) {
    if(*(b.find(*vit)) != *vit) {
      cout << "Incorrect return value when finding " << *vit << endl;
      return -1;
    }
  }
  cout << "Find item test passed!" << endl;


  /* Sort the vector, to compare with inorder iteration on the BST */
  sort(v.begin(),v.end());


  /* Test BST iterator; should iterate inorder */
  cout << "Performing iterator test ...." << endl;
  cout << "traversal using iterator:" << endl;
  vit = v.begin();
  BST<int>::iterator it = b.begin();
  for(; vit != ven; ++vit) {
    cout << *it << endl;
    if(*it != *vit) {
      cout << *it << "," << *vit << ": Incorrect inorder iteration of BST." << endl;
      return -1;
    }
    ++it;
  }
  cout << "Iterator test passed!" << endl;
  
  cout << "Great! All tests passed!" << endl; 
  cout << "Keep in mind that this testbench is not comprehensive." << endl; 
  cout << "We will use more complicated testbench to grade your project" << endl;
}
