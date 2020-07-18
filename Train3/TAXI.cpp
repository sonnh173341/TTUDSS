#include<bits/stdc++.h>
#define Max 30
using namespace std;
int c[Max][Max];
int k, n;
int c_min = 1e6;
int min_cost = 1e6;
int cost = 0;
bool visited[Max];


void solution(int v){
    int tmp = cost + c[v+n][0];
    min_cost = min(tmp, min_cost);
}

void Try(int k, int pre_pos){ // tu vi tri pre_pos toi v
    for(int v = 1; v <= n; v++){
        if(!visited[v]){
            visited[v] = 1;
            cost = cost + c[pre_pos][v] + c[v][v+n];
            if(k == n) solution(v);
            else {
                if(cost + c_min * (2*n - 2*k +1) < min_cost) Try(k +1 , v + n);
            }
            cost = cost - c[pre_pos][v] - c[v][v+n];
            visited[v] = 0;
        }
    }
}

void input(){
    cin >> n;
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