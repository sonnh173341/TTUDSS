#include<bits/stdc++.h>
#define Max 40
using namespace std;
int n, b;
int a[Max], c[Max];

int F(int x, int y){ // duyet toi mon han x, tong khoi luong con lai la 
    if( x == 0) return 0;

    if(a[x] <= y) return max(F(x- 1, y), c[x] + F(x- 1, y - a[x]));

    return F(x- 1, y);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n>> b;
    for (int i = 1; i<=n; i++) cin >> a[i] >>c[i];
    cout << F(n, b)<< endl;
    return 0;
}