#include<bits/stdc++.h>
#define Max 10010
using namespace std;
int X[Max], Y[Max], n, m;
int s[Max][Max];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n>> m;
    
    for (int i = 1; i <= n; i++) { cin>>X[i]; s[i][0] = 0;}
    for (int i = 1; i <= m; i++) { cin>>Y[i]; s[0][i] = 0;}

    for(int i = 1; i <= n ; i++){
        for( int j = 1; j <= m; j++){
            if(X[i] == Y[j]) s[i][j] = s[i-1][j-1] + 1;
            else s[i][j] = max(s[i-1][j], s[i][j-1]);
        }
    }

    cout<<s[n][m]<<endl;
    return 0;
}