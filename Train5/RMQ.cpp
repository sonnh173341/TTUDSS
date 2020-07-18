#include<bits/stdc++.h>
using namespace std;
const int N =  1000010;
int M[N][21];
int n, m;
int a[N];

void input(){
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];

    for(int i = 0; i < n; i++) M[i][0] = i;

    for(int j = 1;  1 << j <= n; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i ++){
            if(a[M[i][j-1]] < a[M[i + (1 << (j -1))][j -1]]) M[i][j] = M[i][j-1];
            else M[i][j] = M[i + (1 << (j-1))][j-1];
        }
    }
    int ans = 0;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int c, d;  cin >> c >> d;
        int k = floor(log2(d - c + 1));
        cout << k << endl;
        if(a[M[c][k]] <= a[M[d - (1 << k) + 1][k]]) ans += a[M[c][k]];
        else ans += a[M[d - (1 <<k) + 1][k]];
    }
    cout << ans;
}

void output(){
    
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
//    cout << floor(log2(3));
   cout << endl ;
   return 0;
}