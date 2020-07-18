#include<bits/stdc++.h>
using namespace std;
const int N = 100010 ;
int n;
typedef pair <int, int> uu;
vector<uu> x[N];
bool visited[N];
int ans, sMax, pre_pos;
void input(){
    cin >> n;
    for(int i = 1; i <= n-1; i ++){
        int u, v, w;
        cin >> u >> v>> w;
        x[u].push_back(uu(v, w));
        x[v].push_back(uu(u, w));
    }
    
}
void Try(int u){
    for(uu z : x[u]){
        int v = z.first;
        int w = z.second;
        if(!visited[v]){
            visited[v] = 1;
            sMax += w;
            if(sMax > ans) {
                ans = sMax;
                pre_pos = v;
            }
            Try(v);
            visited[v] = 0;
            sMax -= w;
        }
    }
}

void solve(){
    ans = sMax = 0;
    for(int i = 1; i <=n; i ++) visited[i] = 0;
    visited[1] = 1;
    Try(1);

    int u = pre_pos;
    ans = sMax = 0;
    for(int i = 1; i <=n; i ++) visited[i] = 0;
    visited[u] = 1;
    Try(u);

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    solve();
    cout << endl;
    return 0;
}