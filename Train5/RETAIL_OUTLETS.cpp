#include<bits/stdc++.h>
using namespace std;
const int N =  110;
int n, m;
int a[N];
const int Mod = 1e9 + 7;
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

void output(){
    int f[110][510];
    f[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = a[i]; j <= m; j++){
            for(int k = j- a[i]; k >= 0; k -= a[i]){
                f[i][j] = (f[i][j] + f[i-1][k]) % Mod;
            }
        }
    }
    
    cout << f[n][m];
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}