#include<bits/stdc++.h>
using namespace std;
const int N =  505;
int a[N];
int p[N];
int m, k, T;

bool check(long long mid, int output = 0){
    long long n_book = 0;
    int n_per = 1;
    int numA = 0;
    if(output) memset(p, 0, sizeof(p));

    for(int i = m; i >= 1 ;i--){
        if(a[i] > mid) return 0;
        if(n_book + a[i] <= mid){
            n_book += a[i];
        }else{
            p[i] = 1;
            n_book = a[i];
            n_per ++;
            numA ++;
        }
    }
    if(output){
        for(int i = 1; i <= m; i++){
            if(numA < k-1 && !p[i]) {
                numA++;
                p[i]=1;
            }
        }
        for(int i = 1; i <= m; i ++){
            cout << a[i] << " ";
            if(p[i]) cout << "/ ";
        }
        cout << endl;
    }
    return n_per <= k;
}

void input(){
    cin >> T;
    while (T--){
        cin >> m >>k;
        for(int i = 1; i <= m; i++) cin >> a[i];
        long long low = 0, hight = 1e10;
            while(hight - low > 1){
                long long mid = (hight + low) /2;
                if(check(mid)) hight = mid;
                else low = mid;
            }
        check(hight, 1);
    }
}

void output(){}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
   input();
   output();
   return 0;
}