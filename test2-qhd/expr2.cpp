#include<iostream>
#define Nmax 35
#define amax 100
using namespace std;
int n , a[Nmax],s,sum,Min,b[Nmax];
long long res;

void init(){
    cin >>n>>sum;
    for (int i = 0 ;i<n;i++){
      cin>>a[i];
      a[i] = abs(a[i]);
      Min = min(Min,a[i]);
      s += a[i];
      b[i+1] = b[i] + a[i] ;//b[1]=a[0] a(x->y) b[y+1]-b[x]
    }
 
}
void Try(int i)
{
   for(int j = 0;j<=1;j++)
    if(s - j*2*a[i]>=sum and s - 2*(b[n]-b[i])<=sum )
       {
           s -= 2*j*a[i];
           if(i==n-1 ) {if(s==sum) res+=1;}
           else Try(i+1);
           s += 2*j*a[i];
 
       }
}
 
 
int main(){
    init();
    Try(1);
    cout<<res%(1000000007);
    return 0;
}