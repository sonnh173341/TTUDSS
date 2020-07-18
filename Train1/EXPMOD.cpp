#include <iostream>
#include <math.h>
using namespace std;
int summod(int a, int b, int c ){
  a = a%c;
  b = b%c;
  if(a+b >c) return a+b-c;
  return a+b;
}
int xmod(int a, int b, int c){
  if(a < b){
    int tmp = a;
    a = b;
    b = tmp;
  }
  if( b == 1) return a%c;
  int tmp = xmod(a, b/2, c);
  tmp = summod(tmp, tmp, c);
  if(b %2 == 0){
    return tmp;
  }else{
    return summod(tmp, a, c);
  }
}
int expmod(int a, int b, int c){
  if( b == 1) return a%c;
  int tmp = expmod(a, b/2, c);
  tmp = xmod(tmp, tmp, c);
  if(b%2 == 0){
    return tmp;
  }else{
    return xmod(tmp, a, c);
  }
}
int main(){
  int a, b;
  cin>>a>>b;
  int c = pow(10, 9)+7;
  int mod = expmod(a, b, c);
  cout<<mod;
  cout<<endl;
  return 0;
}