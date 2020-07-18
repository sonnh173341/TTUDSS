#include<bits/stdc++.h>
using namespace std;
const int N =  35;
vector<int> x[N];
int visited[N];
int node;
int n, m;
vector<int> p;
int ans = 0;
void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
}

void solution(int v){
   ans = max(ans, node);
}
bool check(int v){
    int stt = 0;
    for(int z : p){
        for(int u : x[v]){
            if(u == z){
                stt ++; break;
            }
        }
    }
    if(stt == p.size()) return true;
    return false;
}

void Try(int u){
    for(int v : x[u]){
        if(check(v) && !visited[v]){
            visited[v] = 1;
            p.push_back(v);
            node ++;
            ans = max(ans, node);
            Try(v);
            p.pop_back();
            node --;
            visited[v] = 0;
        }
    }
}

void output(){
    for(int i = 1; i <= n; i ++){
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        node = 1;
        p.clear();
        p.push_back(i);
        Try(i);
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