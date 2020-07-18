#include<bits/stdc++.h>
using namespace std;
const int N =  10010;
int a[N];
int sum[N];
int n, q;

void input(){
    cin >> n >> q;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if((sum[i] - sum[j-1]) % q == 0) ans ++;
        }
    }

    cout << ans;
}

void output(){}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}