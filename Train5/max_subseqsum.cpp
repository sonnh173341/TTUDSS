#include<bits/stdc++.h>
#define Max 1000010
using namespace std;
int a[Max];
int n;
int s[Max];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    s[1] = a[1];
    for (int i = 2; i<=n; i++){
        if(s[i-1] > 0) s[i] = a[i] + s[i-1];
        else s[i] = a[i];
    }
    cout << *max_element(s+1, s+n+1)<< endl;
    return 0;
}