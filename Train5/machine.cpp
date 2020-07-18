#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N = 2000010;
const int INF = 1e9;
int n;
vector<int> a[N];
int maxLen[N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1; i<=n; i++){
        int s, t;
        cin>>s>>t;
        a[t].push_back(s);
    }

    for(int i = 0; i < N; i++){
        maxLen[i] = -INF ;
        for(int s : a[i]){
            maxLen[i] = max(maxLen[i], i - s);
        }
        if(i) maxLen[i] = max(maxLen[i] , maxLen[i-1]);
    }

    int res = -1;

    for(int t = 0; t <= N; t++){
        for(int s : a[t]){
            res = max(res, t- s + maxLen[s-1]);
        }
    }

    cout<<res<<endl;

    return 0;
}