#include<bits/stdc++.h>
using namespace std;
const int N = 510;
long F[N][N], n, m, a[N][N];

void input(){
    cin>>n>>m;
    for(int i = 0 ;i<n;i++)
        for(int j = 0 ;j<m;j++)
            cin>>a[i][j];
}
void output(){
    for(int i = 0 ;i<m;i++)
        F[0][i]=a[0][i];
    for(int i = 1;i<n;i++){
       
       for(int j = 0 ; j<m;j++){
            if(j==0) F[i][0]=F[i-1][0]+a[i][0];else
            F[i][j]=min(F[i-1][j],F[i][j-1])+a[i][j];
        
       }  
       for(int j = m-2 ; j>=0;j--)
            F[i][j]=min(F[i][j],F[i][j+1]+a[i][j]);    
    }

    for(int i = 1 ;i<m;i++)
        F[n-1][0]=min(F[n-1][0],F[n-1][i]);
    cout<<F[n-1][0];
}

int main(){
    input();
    output();
    cout << endl;
    return 0;
}
