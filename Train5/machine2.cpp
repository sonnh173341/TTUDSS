//do phuc tap O(NlogN)
/*
    b1 : Sắp xếp theo chiều tăng của t.
    Tạo mảng tmp[i] : khoảng cách t - s lớn nhất từ 1 tới i
    khi xét tới s[i] và t[i] => xét các t[j] sao cho t[j] < s[i] => cập nhập ans = max(ans, t[i] - s[i] + tmp[j])
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N = 1e7;
int n;
int a[N];

int tmp[N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n ; i++) {
        int s, t;
        cin>> s>>t;
        a[t] = s;
    }
    
    int ans = -1;
    int tmp1 = 0;

    for(int i = 1; i < N ; i++){
        if(a[i] != 0) tmp1 = max(tmp1, i - a[i]);
        tmp[i] = tmp1;
    }

    for (int i = 1; i < N; i++){
        if(a[i] && tmp[a[i] - 1]) ans = max(ans, i - a[i] + tmp[a[i] - 1]);  
    }
    cout<<ans<<endl;
    return 0;
}