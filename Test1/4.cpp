#include<bits/stdc++.h>
using namespace std;
const int N =  1000010;
int n;
int a[N];
int f[N], g[N], f1[N], g1[N];
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

void output(){
    int hight, depth;
    f[1] = g[1] = f1[n] = g1[n] = 1;

    for(int i = 2; i <= n; i++){
        if(a[i] > a[i-1] ){
            f[i] = f[i-1] + 1;
            g[i] = 1;
        }else{
            f[i] = 1;
            g[i] = g[i-1] + 1;
        }
    }
    for(int i = n - 1; i >= 1; i --){
        if(a[i] > a[i+1]){
            f1[i] = f1[i+1] + 1;
            g1[i] = 1;
        }else{
            f1[i] = 1;
            g1[i] = g1[i+1] + 1;
        }
    }
    for(int i = 1; i <= n; i ++) 
    cout << f[i] << " " << g[i] << " " << f1[i] << " " << g1[i]<< endl;
    for(int i = 1; i < n; i ++){
        hight = max(hight, min(f[i] - 1, f1[i] -1));
        depth = max(depth, min(g[i] - 1, g1[i] -1));
    }
    cout << hight << " " << depth << endl;
    

}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}