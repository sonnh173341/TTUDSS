#include<bits/stdc++.h>
using namespace std;
const int N =  1000010;
int n, m;
int a[N];
int f[N][21];

void input(){
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];

    for(int i = 1; i < n ; i++) f[i][0] = i;

    for(int j = 1; 1 << j <= n; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            if(a[f[i][j-1]] < a[f[i + (1 << (j-1))][j-1]]) f[i][j] = f[i][j-1];
            else f[i][j] = f[i + (1 << (j-1))][j-1];
        }
    }
    int ans = 0;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int c ,d;
        cin >> c >> d;
        int k = floor(log2(d - c + 1));
        ans += min(a[f[c][k]] , a[f[d - (1 << k) + 1][k]]);
    }
    cout << ans;
}

void output(){}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}