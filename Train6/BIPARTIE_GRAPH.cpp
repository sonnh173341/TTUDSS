#include<bits/stdc++.h>
using namespace std;
const int N = 100010 ;
vector<int>x[N];
int color[N];
int n, m;
int isbipartie = 1;
void dfs(int u){
    for(int v : x[u]){
        if(color[v] == -1){
            color[v] = !color[u];
            dfs(v);
        }
        else if (color[v] == color[u]){
            isbipartie = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    memset(color, -1, sizeof(color));
    for (int i = 1 ; i <= m; i++){
        int u, v; cin >> u >> v;
        x[u].push_back(v); x[v].push_back(u);
    }

    for(int i = 1; i <=n ; i++){
        if(color[i] == -1){
            color[i] = 0;
            dfs(i);
        }
    }
    cout << isbipartie;
    cout << endl;    
    return 0;
}