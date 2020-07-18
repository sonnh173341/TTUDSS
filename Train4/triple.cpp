#include<bits/stdc++.h>
#define Max 6000
using namespace std;
int a[Max];
int n, k;
int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k;
   int ans = 0;
   for (int i=1; i <=n ; i++) cin>>a[i];

   sort(a+1, a+n+1);

   for(int i = 1; i <= n-2; i++ ){
       for(int j= i+1; j<=n-1; j++){
           int l = j+1;
           int r = n;
           while(r - l > 1){
               int m = (r+l)/2;
               if(a[i] + a[j] + a[m] ==k){
                   ans++;
               }
               else if(a[i] + a[j] + a[m] < k){
                   l = m;
               }else r = m;
           }
       }
   }
   
   cout<<ans<<endl;
   return 0;
}
