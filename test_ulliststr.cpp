#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");
  dat.push_front("i");
  dat.push_front("halo");
  dat.push_back("world");
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  cout << dat.get(3) << " " << dat.get(4) << " " << dat.get(5) << endl;
  dat.pop_back();
  dat.pop_front();
  cout << dat.front() << " " << dat.back() <<endl;


  
  // prints: 8 7 9
  //cout << dat.size() << end;  // prints 3 since there are 3 strings stored
}
