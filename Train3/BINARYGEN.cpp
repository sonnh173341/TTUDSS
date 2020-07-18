#include<iostream>
#include<math.h>
using namespace std;
#define Max 20000
int C[Max], n ;
void input(){
  cin>>n;
  string str;
  cin>>str;
  int k =n-1;
  while(str[k] == '1') k--;
  if(k>=0){
    str[k] = '1';
    for(int i = k+1; i<n; i++) str[i] = '0';
    cout<<str<<endl;
  }else{
    cout<<-1<<endl;
  }
}
int main(){
  input();
  return 0;
}