#include<bits/stdc++.h>
using namespace std;
const int N = 100010 ;

int n;
int x[N];
void input(){
    cin >> n;
    for (int i = 1; i <= n-1; i++){
        int u, v; cin >> u >> v;
        x[u] ++;
        x[v] ++;
    }
    int ans = 0;
    for (int i = 2; i <=n; i++){
        if(x[i] == 1 ) ans ++;
    }
    cout <<ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    
    cout << endl;
    return 0;
}