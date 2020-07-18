#include<bits/stdc++.h>
#define MAX 205
using namespace std;

int n, m ,k, q;
int x[55], d; // chua cac dinh tren duong di duoc chon
int W1, W2, minW1, minc, minc2;  // tong trong so w1, w2 tren duong di
typedef pair<int, int> ww; // chua (w1, w2) cua 1 canh noi
typedef pair<int, ww> vw; // chua dinh ke va trong so tuong ung
vector<vw> a[MAX]; // danh sach ke (dinh ke, w1, w2)
int choosed[55]; // danh dau dinh da chon hay chua

void input(){
    minc2 = minc = MAX;
    cin >> n >> m >> k >> q;
    int uu, vv, w11, w22;
    pair<int, int> w;
    for(int i = 1; i<=m; i++){
        cin >> uu >> vv >> w11 >> w22;
        w = make_pair(w11, w22);
        a[uu].push_back(vw(vv, w));
        a[vv].push_back(vw(uu, w));
        minc = min(minc, w11);
        minc = min(minc, w22);
    }
}

void solution(){
    if(W1 < minW1 && W2 <=q){
        minW1 =  W1;
    }
}

void TRY(int t){
    int u = x[t-1];
    for(int i = 0; i<a[u].size(); i++){
        int v = a[u][i].first;
        if(choosed[v] == 0 && W1 + minc * (k-t+1) < minW1 && W2 + minc*(k-t+1) <= q){
            choosed[v] = 1;
            x[t] = v;// cout << endl << v;
            W1 += a[u][i].second.first;
            W2 += a[u][i].second.second;
            
            if(t == k+1) solution();
            else TRY(t+1);
            choosed[v] = 0;
            W1 -= a[u][i].second.first;
            W2 -= a[u][i].second.second;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    minW1 = 1000000;
    for(int i = 1; i<=n; i++){
        x[1] = i;
        choosed[i] = 1;
        TRY(2);
        choosed[i] = 0;
    }
    cout << minW1 << endl;
}