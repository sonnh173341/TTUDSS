#include<bits/stdc++.h>
#define Max 410
using namespace std;
int n, m;
int c[Max][Max]; //ma tran chi phi

bool check[Max];
int cost_min = 1e9;
int cost = 0;
int min_c = 1e6 + 1;
int count_city = 1;

void input(){
    cin >> n>> m;
    for(int k = 1; k <=m; k++ ){
        int x, y, z;
        cin >> x >> y >> z;
        c[x][y] = z;
        min_c = min(z, min_c);
    }
}
void solution(int v){
    if(c[v][1]){
        int tmp = cost + c[v][1];
        cost_min = min(tmp, cost_min);
    }
}

void Try(int k){ // xuat phat tu k toi thanh pho v
    for(int v = 2; v<=n; v++){
        if( !check[v] && c[k][v] ){
            check[v] = 1;
            count_city++;
            cost += c[k][v];
            if(count_city == n) solution(v);
            else{
                if(cost_min >= cost + min_c*(n - count_city + 1)) Try(v);
            }
            cost -= c[k][v];
            count_city --;
            check[v] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    Try(1);
    cout<<cost_min<<endl;
    return 0;
}