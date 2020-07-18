#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 40;
int a[N][N]; // mang luu mon thu i do nhung giao vien nao
int b[N][N];
int t[N][N];
int sz[N];
int ss[N];
int f_best;
int x[N];
int f[N]; // tong trong luong cua cac giao vien

void input(){
    cin >> m >> n;
    for (int i = 1; i <=m; i++){
        cin >> sz[i];
        for(int j = 1; j<=sz[i]; j++) cin >> b[i][j];
    }

    for (int i = 1; i<=n; i++){
        ss[i] = 0;
        int c = 1;
        for(int j = 1; j<=m; j++){
            for(int k = 1; k <=sz[j]; k++){
                if(b[j][k] == i){
                ss[i] ++;
                a[i][c++] = j;
            }
            }
        }
    }

    int k; cin >> k;
    for(int i = 1; i <= k; i++){
        int c, d; cin >> c>> d;
        t[c][d] = 1;
    }
}

int check(int v, int k){ // kiem tra xem giao vien thu v da xet day mon i chua
    for(int i = 1; i <= k-1; i++){
        if(t[i][k] && x[i] == v ) return 0;
    }
    return 1;
}

void solution(){
    int Max =  0;
    for(int i = 1; i <= m; i++) Max = max(Max, f[i]);
    f_best = min(Max, f_best);
}

void TRY(int k){ // xet toi mon hoc thu k
    for(int i = 1; i <= ss[k]; i++){
        int v = a[k][i]; // giao vien v
        if(check(v, k)){
            x[k] = v; // mon hoc thu k dc day boi v
            f[v] += 1;
            if(k == n){
                solution();
            }else TRY(k+1);
            f[v]-=1;
        }
    }
}

void solve(){
    f_best = 10000;
    for(int i = 1; i<=m; i++){
        f[i] = 0;
    }
    TRY(1);
    if(f_best == 10000) cout << -1 << endl;
    else cout << f_best << endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    solve();
}