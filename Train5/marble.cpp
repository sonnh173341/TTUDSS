#include<bits/stdc++.h>
using namespace std;
const int N =  610;
int f[N][N];
int w, h, n;
int W[N], H[N];
void input(){
    cin >> w >> h >> n;
    for(int i = 1; i <= n;  i++) cin >> W[i] >> H[i];
}

void output(){
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            f[i][j] = i * j;
            for(int k = 1; k <=n; k++) if(W[k] == i && H[k] == j) f[i][j] = 0;
            for(int k = 1; k <= i; k++) f[i][j] = min(f[i][j], f[k][j] + f[i-k][j]);
            for(int k = 1; k <= j; k++) f[i][j] = min(f[i][j], f[i][k] + f[i][j-k]);
        }
    }
    cout << f[w][h];
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}