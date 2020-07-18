#include<bits/stdc++.h>
using namespace std;
const int N =  100010;
vector<int> x[N];
int n;
int parent[N];
queue<int> Q;
bool visited[N];

void input(){
    cin >> n;
    for(int i = 1; i <= n-1; i ++){
        int u, v; cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
}

void bfs(){
    visited[1] = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v : x[u]){
            if(!visited[v]){
                visited[v] = 1;
                Q.push(v);
                parent[v] = u;
            }
        }
    }
}

void output(){
    Q.push(1);
    bfs();
    for(int i = 2; i <= n; i ++) cout << parent[i] << " ";

}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}