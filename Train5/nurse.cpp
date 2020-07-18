/*
    a : la ngay nghi viec dau tien la ngay thu a : k1 <= a-0-1 <=k2 (ngày 1 là ngày nghỉ việc đầu tiên thì có 1 cách chọn)
    b : là ngày nghỉ việc cuối cùng là ngày thứ b : k1 <= n+1 - b- 1< <= k2
    c : là ngày thứ c1, c2 là ngày nghỉ việc : k1 <= c2- c1 -1 <= k2
*/

#include<bits/stdc++.h>
#define Max 1010
using namespace std;
const int Mod = int(1e9) + 7;
int f[Max];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k1, k2;
    cin>> n>> k1>> k2;
    f[0] = f[1] = 1; // giả sử ngày thứ 0 là ngày nghỉ đầu
    for(int i = 2; i <=n+1; i++){
        for(int j = max(0, i- k2- 1); j <= i-k1-1; j++) f[i] = (f[i] + f[j])%Mod;
    }
    cout<< (f[n]+ f[n+1])%Mod<< endl;
    return 0;
}