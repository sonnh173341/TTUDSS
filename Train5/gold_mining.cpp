#include<bits/stdc++.h>
#define Max 100001

using namespace std;
int n, l1, l2;
int f[Max];
int a[Max];

int main(){
    cin>>n>>l1>>l2;
    for(int i = 1; i<=n; i++) cin>>a[i];

    for(int i = 1; i<=l1; i++) f[i] = a[i];
    int max = a[1];
    for(int i = l1+1 ; i<=n; i++ ){
        for(int j = l1; j<=l2; j++){
            if( i>j && f[i] < f[i-j] + a[i]) f[i] = f[i-j] + a[i];
        }
    }
   cout<<*max_element(f+1, f+n+1)<<endl;
}