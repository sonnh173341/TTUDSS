#include<bits/stdc++.h>
using namespace std;
const int N = 100010 ;
int n, m, k;
typedef pair <int, int> vv;
int b[N];
int ans;
vector<vv> x[N];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v>> w;
        x[u].push_back(vv(v, w));
        x[v].push_back(vv(u, w));
    }
    cin >> k;
    for(int i = 1; i <= k; i++) cin >> b[i];
}

void output(){
    ans = 0;
    int stt = 1;
    for(int i = 2; i <= k; i++){
        int test = ans;
        for(vv z : x[i]){
            int v =  z.first;
            int w = z.second;
            if(v == b[i-1]){
                ans += w;
                break;
            }
        }
        // if(test == ans){
        //     stt = 0; break;
        // }
    }
    cout << ans;
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}