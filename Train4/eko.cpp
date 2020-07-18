#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
int n;
long long m;
long long a[N];
long long getW(long long u){
    long long num = 0;
    for(int i = 1; i<=n; i++){
        if(a[i] >= u) num += a[i] - u;
    }
    return num;
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m;
   for(int i = 1; i<=n; i++) cin>>a[i];
   long long low = 0, hight = 1e9+10;
   while(hight - low > 1 ){
       long long mid = (hight+low)/ 2;
       long long num = getW(mid);
       if(num >= m) low = mid;
       else hight = mid;
   }
   cout<<low<<endl;
   return 0;
}