#include <iostream>
#include <typeinfo>
using namespace std;






int main() {
  double* b= new double[6];
  cout<<typeid(_msize(b)).name()<<endl;
  cout<<"hello."<<endl;
  char a;
  cin.get(a);
  return 0;
}
