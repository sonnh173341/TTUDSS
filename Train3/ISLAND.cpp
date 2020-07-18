#include<iostream>
using namespace std;
#define Max 2001
int C[Max][Max], qx[500000], qy[500000], head, tail, s, sMax, num, n,m, x, y;
void input(){
  cin>>n>>m;
  char s[Max];
  for(int i= 1; i<=n; i++){
    cin >> s;
    for(int j=1; j<=m; j++){
      if(s[j-1] == '0') C[i][j] = 0;
      if(s[j-1] == '1') C[i][j] = 1;
    }
  }
}
void pop(){
  x = qx[tail];
  y = qy[tail];
  tail++;
}
void push(int i, int j){
  if(C[i][j] == 0) return;
  s++; head++;
  qx[head] = i;
  qy[head] = j;
  C[i][j]=0;
}
void findland(int i, int j){
  head = tail = 0;
  s++;
  qx[0] = i;
  qy[0] = j;
  C[i][j]=0;
  while(head>= tail){
    pop();
    push(x, y+1);
    push(x, y-1);
    push(x-1, y);
    push(x+1, y);
  }
}
void solve(){
  sMax = 0; num =0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<= m; j++){
      if(C[i][j] == 1){
        num ++; s= 0;
        findland(i, j);
        if(s > sMax) sMax = s;
      }
    }
  }
  cout<<num<<endl<<sMax<<endl;
}
int main(){
  input();
  solve();
  return 0;
}