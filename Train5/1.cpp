#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i < (int)(n); i++)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<pii> spii;
typedef si::iterator sit;

int c[3001];
int a[3001];
int dp[3001][102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   
    int N, K;
    cin >> N >> K;
    
    fore(i, 1, N) cin >> c[i];
    fore(i, 1, N) cin >> a[i];
    
    fore(j, 1, K+1) dp[1][j] = c[1];
    
    fore(i, 2, N) {
        fore(j, 2, K+1) {
            int _max = 0;
            for (int h = 1; h < i; ++h) {
                if (a[h] + h >= i && dp[h][j-1]) {
                    _max = max(_max, dp[h][j-1] + c[i]);
                }
            }
            
            dp[i][j] = _max;
        }
    }
    
    int res = dp[N][K+1];
    if (res == 0) cout << -1;
    else cout << res;
    
	return 0;
}