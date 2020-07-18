#include<bits/stdc++.h>
using namespace std;
const int N = 100010 ;
vector<int> x[N];
queue<int> y;
int n, m;
bool visted[N];
int trace[N];
void bfs(){
    while(!y.empty()){
        int u = y.front();
        y.pop();
        visted[u] = 1;
        for(int v : x[u]){
            if(!visted[v]){
                y.push(v);
                trace[v] = u;
            }
    }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ;
    for (int i = 1; i <= n-1; i ++){
        int u, v; cin >> u >>v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
    // int a = 2, b = 6;
    y.push(1);
    bfs();
    // if (!trace[b]) cout << "Not" << endl;
    // else{
    //     while(b != a){
    //         cout << b << " <- ";
    //         b = trace[b];
    //     }
    //     cout <<a;
    // }
    for (int i = 2; i <=n; i++){
        cout << trace[i]<< " ";
    }
    cout << endl;
    return 0;
}