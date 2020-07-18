#include <iostream>
#include <math.h>
using namespace std;
int main(){
  unsigned long long a, b;
  cin>>a>>b;
  int p = pow(10, 9)+7;
  a = a%p;
  b = b%p;
  int tmp = p-a;
  if(b > tmp){
    cout<<b-tmp;
  }else{
    cout<<a+b;
  }
  cout<<endl;
  return 0;
}