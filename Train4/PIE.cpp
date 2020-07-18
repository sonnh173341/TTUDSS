#include<bits/stdc++.h>
#define Max 100010
using namespace std;
int n, f;
const double PI = acos(-1);
int r[Max];
double a[Max];
int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   int tc;
   cin>>tc;
   while(tc--){
       cin>>n>>f;
       for(int i=1; i<=n; i++){
           cin>>r[i];
           a[i] = PI * r[i]*r[i];
       }
       double low = 0, hight = 1e13;
       for(int it = 0; it<=100; it++){
           double mid = 0.5*(low+hight);
           int num = 0;
           for(int i= 1; i<=n; i++){
               num += floor(a[i]/mid);
           }
           if(num >= f+1) low = mid;
           else hight = mid;
       }
       cout<<fixed<<setprecision(6)<<low<<endl;
   }
   return 0;
}