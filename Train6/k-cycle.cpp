#include<bits/stdc++.h>
using namespace std;
const int N =  35;
vector<int> x[N];
int test;
int visited[N];
int edges;
int ans;
int n, m , k;
void input(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
}

void solution(int v){
    for(int z : x[v]){
        if(z == test){
            ans ++ ; break;
        }
    }
}

void Try(int u){
    for(int v : x[u]){
        if(!visited[v]){
            visited[v] = 1;
            edges ++ ;
            if(edges == k-1) solution(v);
            else Try(v);
            visited[v] = 0;
            edges --;
        }
    }
}

void output(){
    memset(visited, 0, sizeof(visited));
    ans = 0;
    for(int i = 1; i<= n; i ++){
        edges = 0;
        test = i;
        visited[i] = 1;
        Try(i);
    }

    cout << ans/2;
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}