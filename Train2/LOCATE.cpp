#include <iostream>
#include <algorithm>
#include <vector> 
#include <utility>
#include <cstring>
#define Max 1005
using namespace std;
int p[2*Max][2*Max], l, c;
vector<pair<int, int >>a,b;

void solve(){
  int max_s =0;
  for(int i=0; i<a.size(); i++){
    for(int j=0; j<b.size(); j++){
      int u = a[i].first - b[j].first;
      int v = a[i].second - b[j].second;
      p[u+Max][v+Max] ++;
      max_s = max(max_s, p[u+Max][v+Max] );
    }
  }
  cout<<max_s<<endl;
  a.clear(); b.clear();
  memset(p, 0, sizeof(p));
}
void input(){
  int T;
  cin>>T;
  while(T--){
    cin>>l>>c;
    for(int i=0; i<l; i++){
      for(int j=0; j<c; j++){
        int x;
        cin>>x;
        if(x == 1){
          a.push_back(make_pair(i, j));
        }
      }
    }
    for(int i=0; i<l; i++){
      for(int j=0; j<c; j++){
        int x;
        cin>>x;
        if(x == 1){
          b.push_back(make_pair(i, j));
        }
      }
    }
    solve();
  }
}
int main(){
  input();
  return 0;
}  

