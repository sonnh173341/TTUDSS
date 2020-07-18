#include<bits/stdc++.h>
#define Max 1000
using namespace std;
int k, m;
int x[Max];
int a[Max];
bool check(long long  u, bool output = 0){
    int res = 1;
    int numA = 0;
    long long cur = 0;
    if(output){
        memset(a, 0, sizeof a);
    }
    for(int i = m; i >= 1; i--){
        if(x[i] > u) return 0;
        if(cur + x[i] <= u ){
            cur += x[i];
        }else{
            cur = x[i];
            res++;
            numA ++;
            a[i] = 1;
        }
    }

    if(output){
        for(int i= 1; i<=m; i++){
            if(numA < k-1 && a[i] == 0){
                numA ++;
                a[i] = 1;
            }
        }
        for(int i = 1; i<=m; i++){
            cout<<x[i]<<" ";
            if(a[i] == 1) cout<<"/ ";
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
        for (int i = 1; i<=m; i++) cin>>x[i];
        long long low = 0, hight = 1e10;
        while(hight - low > 1){
            long long mid = (low+hight)/2;
            if(check(mid)) hight = mid;
            else low = mid;
        }
        check(hight, 1);
   }
   return 0;
}