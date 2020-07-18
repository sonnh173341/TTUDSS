#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

vector<int> x[N];
bool visited[N];
int n, m;

void dfs(int u){
    visited[u] = 1;
    for(int v : x[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i = 1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
    int count = 0;
    for(int i= 1; i<=n; i++){
        if(!visited[i]){
            count ++;
            dfs(i);
        }
    }
    cout << count <<endl;
    
}

