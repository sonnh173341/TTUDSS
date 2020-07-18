#include<bits/stdc++.h>
using namespace std;
const int N = 100010 ;
vector<int> x[N];
int root;
int n, m;
bool visited[N];
int num[N], low[N];
int t;
int brigde;
int isArti[N];
int numChild;

void dfs(int u, int p){ // p la cha u
    visited[u] = 1;
    num[u] = ++t;
    low[u] = num[u];
    for(int v : x[u]){
        if(v == p) continue;
        if(visited[v]){
            low[u] = min(low[u], num[v]);
        }else{
            if(u == root) numChild++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > num[u]) brigde ++;
            if(low[v] >= num[u]) isArti[u] = 1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >>u>>v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
    for(int i = 1; i <=n; i++){
        if(!visited[i]){
            root = i;
            numChild = 0;
            dfs(i, -1);
            isArti[i] = numChild > 1;
        }
    }
    int arti = 0;
    for(int i = 1; i <= n; i++){
        arti += isArti[i];
    }
    cout << arti << " "<< brigde;
    cout <<endl;
    return 0;
}