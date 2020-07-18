#include<bits/stdc++.h>
using namespace std;
const int N =  20;
int a[N];
int n;
bool visited[N];
bool check(int a, int b){
    return a <= b;
}
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, check);
}

void output(){
    int maxN = 0;
    int ans = 0;
    for(int i = 1; i < n; i ++){
        if(!visited[i]){
            maxN = a[i];
            for(int j = n; j > i; j--){
                if(!visited[j]){
                    maxN += a[j];
                    if(maxN <= 6) {
                        visited[j] = 1;
                    }
                }
            }
            ans ++;
            visited[i] = 1;
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