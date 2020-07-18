#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
int a[N];
int sum[N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >>a[i];

    for(int i = 1; i <=n; i++){
        if(sum[i-1] < 0 ) sum[i] = a[i];
        else{
            
            sum[i] = a[i] + sum[i-1]; 
        }
    }
    cout << *max_element(sum+1, sum +n +1)<<endl;
    return 0;
}