#include<bits/stdc++.h>
using namespace std;
const int N =  1000010;
int a[N];
int ans[N];
int w[N];
int h[N];
int b[N];
void input(){
  while(true){
    int n; cin >> n;
    if(!n) break;
    for(int i = 1; i <= n; i ++){
      cin >> a[i]; ans[i] = a[i]; b[i] = 1;
      w[i] = a[i]; h[i] = 1;
    }
    for(int i = 2; i <= n; i ++){
      if(a[i] >= h[i-1]){
          w[i] = w[i-1] + 1;
          ans[i] = w[i] * h[i-1];
      }
      
    }

  }
}

void output(){}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}