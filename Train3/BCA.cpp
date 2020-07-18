#include<bits/stdc++.h>
using namespace std;
const int N =  35;
int n, m;
int t[N][N];
int f_best;
int f[N];

vector<int> c[N];
vector<int> tmp[N];
void input(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        int k; cin >> k;
        for(int j = 1; j <= k; j ++){
            int x; cin >> x;
            c[x].push_back(i);
        }
    }
    int d; cin >> d;
    for(int i = 1; i <= d; i++) {
        int m, n; cin >> m >> n;
        t[m][n] = 1;
        t[n][m] = 1;
    }
}

bool check(int k, int u){
    for(int v : tmp[u]){
        if(t[k][v] || v == k) return 0;
    }
    return 1;
}

void solution(){
    int Max = 0;
    for(int i = 1; i <= m; i++) Max = max(Max, f[i]);
    f_best = min(f_best, Max); 
}

void Try(int k){ // xet toi mon hoc thu k
    for(int u : c[k]){
        if(check(k, u) ){
            if(f[u] + 1 > f_best) continue;
            
            tmp[u].push_back(k);
            f[u] ++;
            if(k == n) solution();
            else Try(k+1);
            tmp[u].pop_back();
            f[u] --;
        }
    }
}

void output(){
    f_best = 35;
    Try(1);
    if(f_best == 35) cout << -1;
    else cout << f_best ;
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}