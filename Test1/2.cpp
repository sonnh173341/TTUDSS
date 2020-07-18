#include <iostream>
#include <string>
#define N 1000000007
#define int long long

using namespace std;

string s;
int f[1077][1077];
int n;
main()
{
    cin>>s;

    s=" "+s;
    n= s.length()-1;
    f[0][0]=1;
    for (int i=1;i<=n;i++)
    {
            if (s[i]=='(') for (int j=0;j<=n;j++) f[i][j]=f[i-1][j-1];

            if (s[i]==')') for (int j=0;j<=n;j++) f[i][j]=f[i-1][j+1];

            if (s[i]=='?') for (int j=0;j<=n;j++) f[i][j]=(f[i-1][j-1]+f[i-1][j+1]) % N;
    }
    cout<<f[n][0] << endl;
}