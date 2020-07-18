#include<bits/stdc++.h>
using namespace std;
const int N =  1000010;
int n, stt0, stt1, up, down;
bool visited[N];
int p[N];
int ans;
queue<int> Q;

void input(){
    cin >> n >> stt0>> stt1>> up >> down;
}

void bfs(){
    while(!Q.empty()){
        int u = Q.front();
        if( u == stt1) {
            ans = 1; cout << p[u];
        }
        Q.pop();
        if(u + up <= n && !visited[u+up]){
            visited[u+up] = 1;
            Q.push(u+up);
            p[u+up] = p[u] + 1;
        }
        if(u - down > 1 && !visited[u-down]){
            visited[u - down] = 1;
            Q.push(u-down);
            p[u - down] = p[u] + 1;
        }
    }
}

void output(){
    ans = -1;
    visited[1] = 1;
    p[stt0] = 0;
    Q.push(stt0);
    bfs();
    if(ans == -1) cout << "use the stairs"; 
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}