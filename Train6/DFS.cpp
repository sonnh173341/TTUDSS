#include<bits/stdc++.h>
using namespace std;
const int N = 10 ;
vector<int> x[N];
bool visited[N];
int trace[N];
int n, m;
void dfs(int u){
    visited[u] = 1;
    for(int v : x[u]){
        if(!visited[v]){
            trace[v] = u;
            // cout << v <<" ";
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
    // cout << "From 2 you can visted :"<<endl;

    //tim duong di tu 1 toi 5
    dfs(1);
    int a = 2, b = 5;
    if (trace[b] == 0) cout << "Not" << endl;
    else{
        while(b != a){
            cout << b << " <- ";
            b = trace[b];
        }
        cout <<a;
    }
    cout << endl;
    return 0;
}