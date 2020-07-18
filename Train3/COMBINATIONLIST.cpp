#include<bits/stdc++.h>
using namespace std;
const int N = 10010 ;
int n,m,k;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >>m>>k;
    int a[m+1];
    int sum = 0;
    for(int i = 1; i<=m; i ++){
        a[i] = i;
        sum +=i;
    }
    int check = 0;
    for(int i = n; i >= n-m+1; i--){
        check +=i;
    }
    int ans = 0;
    while(sum != check){
        ans++;
        if (ans == k) {
            for(int i = 1; i <=m ; i++) cout << a[i]<<" ";
            break;
        }else{
            int id;
            for (int i = m; i >=1 ; i--) {
                if (a[i] != n-m +i){
                    a[i] ++;
                    id = i;
                    break;
                }
            }
            for (int j = id+1; j<=m; j++) a[j] = a[j-1]+1;
            int sum_check = 0;
            for(int i = 1; i <=m ; i++) sum_check += a[i];
            sum = sum_check;
        }
    }
    ans++;
    if (ans == k) for(int i = 1; i <=m ; i++) cout << a[i]<<" ";
    if(ans < k) cout << -1;
    cout <<endl;
    return 0;
}