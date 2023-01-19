/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"

using namespace std;

void display(Node*& a);

int main(int argc, char* argv[])
{
  Node* a = new Node(2,nullptr);
  Node* b = new Node(99, a);
  Node* c = new Node(5,b);
  Node* d = new Node(18,c);
  Node* e = new Node(37,d);
  Node* f = new Node(82,e);
  
  Node* odds = nullptr;
  Node* evens = nullptr;

  split(f,odds,evens);

  display(odds);
  cout <<endl;
  display(evens);
  cout <<endl;

  delete a;
  delete b;
  delete c;
  delete d;
  delete e;
  delete f;

  return 0;
}

void display(Node*& a){
  cout << a->value << " ";
  if (a->next){
    display(a->next);
  }
}
