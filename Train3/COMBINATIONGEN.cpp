#include<bits/stdc++.h>
using namespace std;
const int N  = 10010 ;
int n, m;
int x[N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i<=m; i ++)  cin >> x[i];
    int stt = 0;
    for (int i = m; i >=1 ; i--) {
        if (x[i] != n-m +i){
            stt = 1;
            x[i] ++;
            for (int j = i+1; j<=m; j++) x[j] = x[j-1]+1;
            break;
        }
    }
    if(stt) for (int i = 1; i <= m; i++) cout << x[i]<<" ";
    else cout << -1;
    cout << endl;
    return 0;
} 