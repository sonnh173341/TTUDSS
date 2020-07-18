#include<bits/stdc++.h>
#define Max 25
using namespace std;
int c[Max][Max];
int k, n;
int c_min = 1e6;
int min_cost = 1e6;
int cost = 0;
int p = 0; // so luong hanh khach tren xe
bool visited[Max];

bool check(int v){
    if(visited[v]) return false; //da tham v
    if( v > n && !visited[v - n] ) return false; //chua don khach tai v-n
    if( v <= n && p >= k) return false; // khong the cho them hanh khach nua len xe
    return true;
}

void solution(int v){
    int tmp = cost + c[v][0];
    min_cost = min(tmp, min_cost);
}

void Try(int k, int pre_pos){ // tu vi tri pre_pos toi v
    for(int v = 1; v <= 2*n; v++){
        if(check(v)){
            visited[v] = 1;
            cost += c[pre_pos][v];
            if(v <= n)  p++; // len xe
            else p--; // xuong xe
            if(k == 2*n) solution(v);
            else {
                if(cost + c_min * (2*n - k +1) < min_cost) Try(k +1 , v);
            }
            cost -= c[pre_pos][v];
            if(v <=n ) p--; // xuong xe
            else p++; // len xe
            visited[v] = 0;
        }
    }
}

void input(){
    cin >> n>> k;
    for(int i = 0; i <= 2*n; i++) for(int j = 0; j <=2*n ; j++) {
        cin >> c[i][j];
        if( i!= j){
            c_min = min(c[i][j], c_min);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    Try(1, 0);
    cout<<min_cost<<endl;
    return 0;
}