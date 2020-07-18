#include<bits/stdc++.h>
using namespace std;
#define Max 1000010
int n, l1, l2;
int a[Max];
int t[Max*4];
int f[Max];
int get(int node, int l, int r, int x, int y){
    if(x>r || y<l) return 0;
    if(x<=l && y>=r ) return t[node];

    int m = (l +r)/2;
    int p1 = get(node*2, l, m, x, y);
    int p2 = get(node*2 +1, m+1, r, x, y);
    return max(p1, p2);
    
}
//Tao ST
void add(int node, int l, int r, int u, int v){
   if(l == r) t[node] = v;
   else{
       int m = (l+r)/ 2;
       if(u<=m) add(node*2, l, m, u, v);
       else add(node*2+1, m+1, r, u, v);
       t[node] = max(t[node*2], t[node*2+1]);
   }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>l1>>l2;

    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i = 1; i<=n; i++){
        f[i] = a[i] + get(1, 1, n, max(0, i- l2), i - l1);
        add(1, 1, n, i, f[i]);
    }
    cout<<*max_element(f+1, f+n+1)<<endl;
}