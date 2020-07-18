#include<bits/stdc++.h>
using namespace std;
const int N = 20010 ;
int n, k, m;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k>> m;
    int x[n+1];
    int t = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(i % m ) x[i] = 0;
        else x[i] = 1;
    }
    while (t != n){
        int stt = 0;
        int dem = 0, tmp = 0;
        for (int i = 1; i <= n; i++){
            if(x[i] == 0){
                dem ++;
                tmp = max(dem, tmp);
            }else dem = 0;
            if(tmp == m){
                 stt = 1;
                 break;
            }
        }
        if(stt == 0) ans ++;
        if(ans == k ){
            for(int i = 1; i<=n; i++) cout << x[i]<<" ";
            break;
        }else{
            int id = n;
            for (int i = n; i >= 1; i--){
                if(x[i] == 0){
                        x[i] = 1;
                        id = i;
                        break;
                    }
            }
            for (int j = id+1; j<=n; j++) x[j] = 0;
            int sum2= 0;
            for (int i = 1; i<=n; i++) sum2 += x[i];
            t = sum2;
        }
        
    }
    ans ++;
    if(ans == k){
        for(int i = 1; i<=n; i++) cout << 1<<" ";
    }
    if(ans < k ) cout << -1;
    cout << endl;
    return 0;
}