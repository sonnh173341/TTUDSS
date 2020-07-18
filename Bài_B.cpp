#include<bits/stdc++.h>

using namespace std;

const int N = 100;

int k;
string s;
int x[N];
string ans = "";
bool check[N];
int length;


void solution(){
    string ans_test = "";

    for(int i = 1; i <= k; i++){
        ans_test += s[x[i]];
    }
    ans = max(ans, ans_test);

}

void Try(int u){

    for(int i = x[u-1] + 1; i <= length; i++){
            x[u] = i;
            check[i] = true;
            if(u == k){
                solution();
            }
            else{
                Try(u+1);
            }
    }
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    cin >> k;
    s = " " + s;
    length = s.size();
    memset(check, false, sizeof check);
    memset(x, 0, sizeof x);

    Try(1);

    cout << ans << endl;
    return 0;
}
