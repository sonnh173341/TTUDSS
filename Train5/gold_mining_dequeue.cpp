#include<bits/stdc++.h>
using namespace std;
#define Max 1000010
int n, l1, l2;
int a[Max];
int f[Max];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>l1>>l2;

    for(int i=1; i<=n; i++) cin>>a[i];

    deque<int> q;
    for(int i = 1; i<=n; i++){
        if(i - l1>0){
            while(!q.empty() && f[q.back()] <= f[i-l1]) q.pop_back();
            q.push_back(i- l1); 
        }
        if(!q.empty() && q[0] == i- l2 -1) q.pop_front();
        f[i] = a[i] +(q.empty() ? 0 : f[q[0]]);
    }
    cout<< *max_element(f+1, f+n+1) <<endl;
}