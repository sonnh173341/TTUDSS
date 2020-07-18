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
typedef set<pii> spii;
typedef si::iterator sit;
 
int N, K;
int a[5001];
 
int bst(int first, int last, int x) {
    if (last - first == 1) {
        if (a[first] == x) return first;
        return 0;
    }
    
    int mid = (first + last) / 2;
    if (a[mid] == x) return mid;
    if (a[mid] > x) {
        bst(first, mid, x);
        
    } else {
        bst(mid, last, x);
    }
}
 
int main() {
    cin >> N >> K;
    
    fore(t, 1, N) {
        cin >> a[t];
    }
    
    sort(a+1, a+N+1);
    ll Q = 0;
    int a1, a2, a3;
    
    for (int i = 1; i < N - 1; ++i) {
        a1 = a[i];
        if (a1 > K) break;
        for (int j = i + 1; j < N; ++j) {
            a2 = a[j];
            if (a2 >= K - a1) break;
            int k = bst(j + 1, N + 1, K - a1 - a2);
            
            if (k > j) {
                ++Q;
                a3 = a[k];
                int tmp = k - 1;
                while (tmp > j && a[tmp--] == a3) ++Q;
                tmp = k + 1;
                while (tmp <= N && a[tmp++] == a3) ++Q;
            }
        }
    }
    cout << Q;
	
	return 0;
}