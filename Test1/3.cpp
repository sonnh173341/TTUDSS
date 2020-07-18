#include<bits/stdc++.h>
using namespace std;
const int N =  20000;
int a[N];
int n, m1, m2;
long long s[N];
void input(){
    cin >> n >> m1 >> m2;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i] = s[i -1] + a[i]; // s[i] bang tong cac phan tu tu 1 ->  i => s[i] - s[j] = tong cac phan tu tu j -> i
    }
}

void output(){
    int ans= 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= i; j++){
            if(s[i] - s[j-1] >= m1 && s[i]- s[j-1] <= m2) {
                cout << i << " " << j; ans ++; cout << endl;
            }
        }
    }
    cout << ans;
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   cout << endl ;
   return 0;
}