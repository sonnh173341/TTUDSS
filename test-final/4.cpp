#include<bits/stdc++.h>
using namespace std;

long  a,b;
int main(){
    cin>>a>>b;
    long ans;
    if(a==b) ans=sqrt(b+b);
    else ans=sqrt(2*min(a,b)+1);
    cout<< ans << endl;
    return 0;
}