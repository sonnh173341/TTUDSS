#include<bits/stdc++.h>
using namespace std;
#define Max 999999999
const int N = 10010 ;

typedef pair<int, int> ii;
int ans[N];
vector<ii> a[N];
int d[N];
int n, m, k;
void dijkstra(int c) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = Max;
    d[c] = 0;
    pq.push(ii(0, c));

    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

void input(){
    cin >> n >> m;
    for (int i = 1; i <=m; i ++){
        int p, q, w;
        cin >> p >> q >> w;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    cin >> k;
    for(int i = 1; i <= k; i ++){
        cin >> ans[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();

    int maxD = 0;
    for(int i = 1; i <= k ; i++){
        memset(d, 0, sizeof(d));
        dijkstra(ans[i]);
        for(int j = 1; j <= k ; j ++){
            if(d[ans[j]] != Max){
                maxD = max(maxD, d[ans[j]]);
            }
        } 
    }
    cout << maxD;
    cout << endl;
    return 0;
}