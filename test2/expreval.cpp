#include<bits/stdc++.h>
using namespace std;
const int N =  2*1e5 + 10;
int n, a[N], b[N], c[N];
const int Mod = 1e9 +7;
long long s ;
void init(){
    cin>>n;
    for (int i = 0 ;i < n;i++) cin>>a[i];
    for (int i = 0 ; i < n-1;i++) cin>>b[i];
}

void Main(){
    for(int i = 0 ; i < n-1; i++){
        if(b[i]==0) a[i+1] *= -1 ;
    }
    for(int i = 0 ;i < n-1;i++){
        if(b[i]==2) {
            a[i+1] *= a[i]; c[i]=true;
        }
    }
    for(int i = 0; i < n ; i++)
      if(!c[i]) s += a[i];
    
    s = s % Mod;
    s = (s >= 0) ? s : (s+Mod);
    cout<< s <<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    init();
    Main();
    return 0;
}