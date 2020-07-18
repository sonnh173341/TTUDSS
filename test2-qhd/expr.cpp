#include<bits/stdc++.h>
using namespace std;
const int N = 35 ;
int a[N];
int cmin = 101, cmax = -101;
int n, b;
int ans = 0;
int num = 0;
void solution(){
    cout <<ans <<endl;
    if(ans == b) num ++;
    ans = a[1];
}
void Try(int k){ // xet toi so k
    for(int i = 0; i <= 1; i++){
        if(i == 1){
            ans = ans + a[k];
            if(k == n) solution();
            else{
                if(ans + cmax*(n-k) >=b && ans - cmin*(n-k) <=b ) Try(k+1);
            }
            ans = ans - a[k];
        }else{
            ans = ans - a[k];
            if(k == n) solution(); 
            else {
                if(ans + cmax*(n-k) >=b && ans - cmin*(n-k) <=b ) Try(k+1);
            }
            ans = ans + a[k];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >>n >> b;
    for (int i = 1; i <= n; i++){
         cin >> a[i];
         cmin = min(cmin, a[i]);
         cmax = max(cmax, a[i]);
    }
    ans = a[1];
    Try(2);
    cout<<num<<endl;
    return 0;
}