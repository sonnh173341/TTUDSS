#include <bits/stdc++.h>

using namespace std;

int block[30][3];
int max_h[30][3];
int n;

int canPlaceOnTop(int b1, int h1, int b2, int h2) {
	int base1[2], base2[2];
	int j1 = 0, j2 = 0;

	for (int i = 0; i < 3; ++i) {
		if (i != h1) base1[j1++] = block[b1][i];
		if (i != h2) base2[j2++] = block[b2][i];
	}

	if (max(base1[0], base1[1]) > max(base2[0], base2[1]) &&
		min(base1[0], base1[1]) > min(base2[0], base2[1])) {

		return 1;
	}
	return 0;
}

int dp(int i, int h) {
	int& ans = max_h[i][h];

	if (ans) return ans;
	ans = block[i][h];

	for (int b = 0; b < n; ++b) {
		for (int j = 0; j < 3; ++j) {
			if (canPlaceOnTop(i, h, b, j)) {
				ans = max(ans, block[i][h] + dp(b, j));
			}
		}
	}

	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;
    cin >> n;
    while 👎 {
    	for (int i = 0; i < n; ++i) {
    		cin >> block[i][0] >> block[i][1] >> block[i][2];
    		max_h[i][0] = max_h[i][1] = max_h[i][2] = 0;
    		// cerr << block[i][0] << " " << block[i][1] << " " << block[i][2] << '\n';
    	}

    	int res = 0;
    	for (int b = 0; b < n; ++b) {
    		for (int j = 0; j < 3; ++j) {
    			res = max(res, dp(b, j));
    		}
    	}
    	cout << "Case " << ++cnt << ": maximum height = "<< res << '\n';
    	cin >> n;
    }


	return 0;
}