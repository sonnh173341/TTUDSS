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

int n, m;
int rmq[1000000][21];
int a[1000000];

int getMinElement(int i, int j) {
    int _len = j - i + 1;
    int k = 0;
    
    while ((1<<(k+1)) <= _len) ++k;
    return min(rmq[i][k], rmq[j - (1<<k) + 1][k]);
}

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a+i);
        rmq[i][0] = a[i];
    }
    for (int j = 1; (1<<j) <= n; ++j) {
        int _len = 1<<(j-1);
        for (int i = 0; i + (1<<j) - 1 < n; ++i) {
            rmq[i][j] = min(rmq[i][j-1], rmq[i + _len][j-1]);
        }
    }
    
    ll res = 0;
    int i, j;
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &i, &j);
        res += getMinElement(i, j);
    }
    printf("%ld", res);
    
	return 0;
}