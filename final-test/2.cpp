#include<bits/stdc++.h>
using namespace std;
const int N = 102;
int n, d, a[N][N];
int minX, minY, maxX, maxY;

void input(){
    cin >> d >> n;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++)
            a[i][j] = 0;
    }

    minX = minY =100;
    maxX = maxY = 1;
    int x, y, s;
    for(int i = 1; i<=n; i++){
        cin >> x >> y >> s;
        a[x][y] = s;
        maxX = max(maxX, x);
        minX = min(minX, x);
        maxY = max(maxY, y);
        minY = min(minY, y);
    }

    //cout << minX << " " << minY << " " << maxX << " " << maxY << endl;
}

int Kill(int x, int y, int d){
    int mminX, mminY, mmaxX, mmaxY;
    mminX = max(1, x - d);
    mmaxX = min(100, x + d);
    mminY = max(1, y -d);
    mmaxY = min(100, y + d);

    // cout <<"----";
    // cout << "\n Giet tai " << x << ", " <<y << ": ";
    // cout << minX << " " << minY << " " << maxX << " " << maxY << endl;

    int sum = 0;
    for(int i = mminX; i<=mmaxX; i++){
        for(int j = mminY; j<=mmaxY; j++){
            sum +=a[i][j];
        }
    }
    //cout << sum;
    return sum;
}

void solve(){
    int ans = 0;
    int ansX = 1, ansY = 1;
    int delta; // so chuot;

    for(int x = minX; x<=maxX; x++){
        for(int y = minY; y<=maxY; y++){
            delta = Kill(x, y, d);
            if(ans < delta){
                ans = delta;
                ansX = x; ansY = y;
            }
        }
    }

    cout << ansX << " " << ansY << " " << ans;
}

int main(){
    input();
    solve();
    cout << endl;
}