#include<bits/stdc++.h>
using namespace std;
const int N = 2010 ;
int stt = 1;
vector<int> x[N];
int a[N]; // gender

void dfs(int u){
    for(int v : x[u]){
        if(a[v] == -1){
            a[v] = !a[u];
            dfs(v);
        }
        else if(a[v] == a[u]){
            stt = 0;
            return;
        }
    }
}

void input(){
    int t; cin >> t;
    int dem = 0;
    while(t--){
        dem ++;
        memset(a, -1, sizeof(a));
        int bs, is; cin >> bs >> is;
        for (int i = 1 ; i <= is; i ++){
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        
        for (int i = 1; i <= bs; i++){
            if(a[i] == -1){
                a[i] = 0;
                dfs(i);
            }
        }

        cout << "Scenario #"<< dem<<":"<<endl;
        if(stt) cout << "No suspicious bugs found!"<<endl;
        else cout << "Suspicious bugs found!"<<endl;

        for(int i = 1; i <= bs; i++){
            x[i].clear();
        }
        stt = 1;
   }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    return 0;
}