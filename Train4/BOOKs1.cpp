#include<bits/stdc++.h>
#define Max 1000
using namespace std;

int k, m;
int p[Max];
int a[Max];
bool check(long long u, int output =0){
    int res = 1;
    long long cur = 0;
    int numA = 0;
    if(output){
        memset(a, 0, sizeof a);
    }
    for(int i = m; i>=1; i--){
        if(p[i] > u) return 0;
        if(cur + p[i] <=u){
            cur += p[i];

        }else{
            a[i] = 1;
            res++;
            cur = p[i];
            numA++;
        }
    }

    if(output){
        for(int i=1; i<=m; i++){
            if(numA < k-1 && a[i] ==0){
                a[i] = 1;
                numA ++;
            }
        }
        for(int i= 1; i<=m; i++){
            cout<<p[i]<<" ";
            if(a[i]) cout<<"/ ";
        }
        cout<<"\n";
    }
    return res <= k;
}
int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   int tc;
   cin>>tc;
   while(tc--){
       cin>>m>>k;
       for(int i= 1; i<=m; i++){
           cin>>p[i];
       }

       long long low = 0; long long hight = 1e10;
       while(hight- low >1){
           long long mid = (hight+low)/2;
           if(check(mid)) hight = mid;
           else low = mid;
       }
       check(hight, 1);
   }
   return 0;
}