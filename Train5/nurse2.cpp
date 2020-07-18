/*
    a[0][i] : ngày thứ i là ngày nghỉ việc
    a[1][i] : ngày thứ i là ngày làm việc
 */
#include<bits/stdc++.h>
#define Max 1010
using namespace std;
const int Mod = 1e9 + 7;
int n, k1, k2;
int s[Max][Max];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k1 >> k2;
    s[0][0] = s[0][1] = s[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = max(0, i-k2) ; j <= i-k1 ; j++){
            s[1][i] = ( s[1][i] + s[0][j]) % Mod;
        }
        s[0][i] = s[1][i-1] % Mod;
    }
    cout<<(s[0][n] + s[1][n]) % Mod<<endl;
    return 0;
}