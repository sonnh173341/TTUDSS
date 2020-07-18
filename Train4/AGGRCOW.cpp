#include<bits/stdc++.h>
#define Max 100010
using namespace std;
int n, c;
int x[Max];

int getCow(int u){
    int res = 0;
    int last = -int(1e9)- 10;
    for(int i= 1;i <=n; i++){
        if(x[i] - last >= u){
            res ++;
            last = x[i];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>c;
        for(int i=1; i<=n; i++) cin>>x[i];

        sort(x+1, x+n+1);
        int low = 0; 
        int hight = int(1e9) +10;
        while(hight- low> 1){
            int mid = (low+ hight)/2;
            int maxCow = getCow(mid);
            if(maxCow >= c) low = mid;
            else hight = mid;
        }
        cout<<low<<endl;
   }
   return 0;
}