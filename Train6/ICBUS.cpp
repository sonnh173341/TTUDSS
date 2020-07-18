#include<bits/stdc++.h>
using namespace std;
const int N = 5005 ;
bool visited[N];
int n, k;
vector<int>x[N];
struct node{
    int dmax;
    vector<int> v;
    int cost;
};
int tmp;
vector<node> l;
bool choose[N];
unsigned long cost = 0;
unsigned long ans = 99999999;

void Try(int u){
    for(int z : l[u].v){
        if(!visited[z]){
            visited[z] = 1;
            cost += l[u].cost;
            if(z == n) ans = min(ans, cost);
            else Try(z);
            cost -= l[u].cost;
            visited[z] = 0;
        }   
    }
}

void dfs(int u, int k, int index){
    for(int z : x[u]){
        if(!visited[z]){
            if(tmp < k){
                tmp ++;
                visited[z] = 1;
                int stt = 1;
                // for(int m : l[index].v){
                //     if(z == m) {
                //         stt =0; break;
                //     }
                // }
                if(stt) l[index].v.push_back(z);
                dfs(z, k, index);
                // l[u].v.pop_back();
                visited[z] = 0;
                tmp --;
            }
        }
    }
}

void bfs(int u, int k){
    queue<int> a;
    a.push(u);
    visited[u] = 1;
    while(tmp < k && !a.empty()){
        int b = tmp;
        int uu = a.front();
        a.pop();
        for(int vv : x[uu]){
            if(!visited[vv]){
                tmp = b+1;
                visited[vv] = 1;
                l[u].v.push_back(vv);
                a.push(vv);
            }
        }
        // tmp ++ ;
    }
}

void input(){
    cin >> n >> k;
    l.reserve(n+1);
    for (int i = 1; i <= n; i++){
        int a, b; cin >> a >>b;
        l[i].cost = a; 
        l[i].dmax = b;
    }
    for (int i = 1; i <= k; i++){
        int u,v ; cin >>u >>v;
        x[u].push_back(v);
        x[v].push_back(u);
    }

    for(int i = 1; i <= n; i ++){
        memset(visited, 0, sizeof(visited));
        tmp = 0;
        // bfs(i, l[i].dmax);
        dfs(i, l[i].dmax, i);

        // for (int z : l[i].v){
        //     cout << z << " ";
        // }
        // cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    memset(visited, 0, sizeof(visited));
    visited[1] = 1;
    Try(1);
    cout << ans;
    cout << endl;
    return 0;
}