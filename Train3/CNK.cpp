#include <iostream>
#define ull unsigned long long
using namespace std;

ull addmod(ull c1, ull c2, ull m){
  c1 = c1%m;
  c2 = c2%m;
  ull tmp = m- c1;
  if(c2 >= tmp) return c2- tmp;
  else{
    ull c = c1+c2;
    return c;
  }
}
ull cnk_mod(ull k, ull n, ull m){
  if( k==0 || k==n) return 1;
  ull tmp = addmod(cnk_mod(k-1, n-1, m), cnk_mod(k, n-1, m), m);
  return tmp;
}
void output(ull k, ull n, ull m){
  cout<<cnk_mod(k, n, m)<<endl;
}
void input(){
  int T;
  ull n,k,m;
  cin>>T;
  for(int i= 0; i<T; i++){
    cin>>n>>k>>m;
    output(k, n, m);
  }
}

int main(){
  input();
  return 0;
}