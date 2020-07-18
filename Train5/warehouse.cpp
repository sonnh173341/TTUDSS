#include<bits/stdc++.h>
using namespace std;
const int N =  1010;
int n, T, D;
int a[N];
int t[N];
void input(){
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> t[i];
}

void output(){
    int f[N][N];
    int ans = 0;
    for(int i  = 1; i <= n; i ++){
        for(int tg = t[i] ; tg <= T; tg++){
            for(int j = max(0, i-D); j <= i-1; j++){
                f[i][tg] = max(f[i][tg], a[i] + f[j][tg - t[i]]);
            }
            ans = max(ans, f[i][tg]);
        }
    }
    cout << ans;
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}