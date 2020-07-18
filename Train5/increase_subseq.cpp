#include<bits/stdc++.h>
#define Max 
using namespace std;
const int N = 1000010;
int a[N];
int s[N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >>n;
    int res = 0;
    for (int i= 1; i<=n ; i++) cin>>a[i];
    for(int i= 2; i<=n; i++){
        s[i] = 1;
        for(int j = 1; j<=i-1; j++){
            if(a[j] < a[i]) s[i] = max(s[i], s[j] +1);
        }
        res = max(res, s[i]);
    }
    cout<<res<<endl;
    return 0;
}