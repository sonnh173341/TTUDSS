#include<bits/stdc++.h>
using namespace std;
const int N = 1010 ;
int n;
int y[N];

void input(){
    cin >> n;
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=n; j++){
            int a; cin >> a;
            if(a) {
                y[i] ++;
                y[j] ++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    int stt = 1;
    for(int i = 1; i <=n; i++){
        if(y[i] != 2*(n-1)) {
            stt = 0;
            break;
        }
    }
    if(stt) cout << 1;
    else cout << 0;
    cout << endl;
    return 0;
}