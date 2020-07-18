#include<bits/stdc++.h>

using namespace std;
const int N = 1010;
int n, l;
int a[N];

bool getDist(double u){
    double last = 0;
    for(int i = 1; i<=n; i++){
        if(a[i] - u <= last) last = a[i]+u;
        else return 0;
    }
    if(a[n] + u < l) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>l;
    for (int i = 1; i<= n; i++) cin >> a[i];
    sort(a+1, a+1 + n);
    double low = 0, hight = l+10;
    for(int it = 1; it <= 150; it++){
        double mid = 0.5*(hight+ low);
        if(getDist(mid)) hight = mid;
        else low = mid; 
    }
    cout<< fixed<< setprecision(10)<< hight<<endl;
    return 0;
}