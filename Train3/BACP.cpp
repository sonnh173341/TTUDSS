#include<bits/stdc++.h>
using namespace std;
const int N =  20;
int n, m;
int ans, cost;
int tmp[N][N];
int choose[N];
int c[N];
int visited[N];
int f[N];
vector<int> temp[N]; // mon hoc i 
vector<int> temp2[N]; // giai doan i
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> c[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j++){
            cin >> tmp[i][j];
            if(tmp[i][j]) temp[i].push_back(j);
        }
    }
}

bool check(int k, int v){ //xet mon hoc k o ki v
    if(!temp[k].size()) return true;
    for(int u : temp[k]){
        if(choose[u] && choose[u] < v) return true;
    }
    return false;
}

void solution(){
    int Max = 0;
    for(int i = 1; i <= m; i++) Max = max(Max, f[i]);
    ans = min(ans, Max);
}

void Try(int k){ // mon hoc thu k dc xep vao ki v
    for(int v = 1; v <= m; v ++){
        if(check(k, v)){
            f[v] += c[k];
            // temp2[v].push_back(k);
            choose[k] = v;
            if(k == n) solution();
            else Try(k+1);
            f[v] -= c[k];
            choose[k] = 0;
            // temp2[v].pop_back();
        }
    }
}

void output(){
    ans = 1e7;
    cost = 0;
    Try(1);

    cout << ans;
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}