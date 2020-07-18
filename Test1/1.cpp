#include<bits/stdc++.h>
using namespace std;
const int N =  100010;
int a[N], b[N];

bool sort_res(int a, int b){
    return b < a;
}
void input(){
    int count = 0;
    int t; cin >> t;
    while(t--){
        count ++;
        int n; 
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n, sort_res);
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            ans += a[i] * b[i];
        }
        cout << "Case #" << count << ": "<< ans; 
        cout << endl;
    }
}

void output(){}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   return 0;
}