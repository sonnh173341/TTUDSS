#include <iostream>
#include <math.h>
using namespace std;
int addmod(int a, int b, int c){
  a = a%c;
  b = b%c;
  int tmp = c-a;
  if(b>tmp){
    return b-tmp;
  }else{
    return a+b;
  }
}
int main(){
  int n;
  int c = pow(10, 9)+7;
  cin >> n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int mod = 0;
  for(int i = 0; i<n; i++){
    mod = addmod(mod, a[i], c);
  }
  cout<<mod;
  cout<<endl;
  return 0;
}