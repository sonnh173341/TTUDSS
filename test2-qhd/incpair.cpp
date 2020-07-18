#include<bits/stdc++.h>
using namespace std;
const int N = 1010 ;
int a[N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n ;i++) cin >> a[i];

    int ans = 0;
    for (int i = 1; i < n; i++){
        for (int j = i+1; j <=n; j++){
            if(a[j] > a[i]) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}