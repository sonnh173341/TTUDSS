#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int d[20];
int n, K, Q;
int R;
int trucks[20];
int counts[20];
unsigned long long  res = 0;

unsigned long long  factorial(int n) { // n!
	if (n == 0) return 1;
	unsigned long long  f = 1;
	for(int i = 2; i <= n; i ++) f *= i;
	return f;
}

void update(){
	unsigned long long tmp = 1;
	for (int i = 1; i <= K; ++i) {
		if (counts[i] == 0) return;
		tmp *= factorial(counts[i]);
	}
	res += tmp;
}

void Try(int k) {
	for(int j = 1; j <= K; j++){
		if (trucks[j] + d[k] <= Q) {
			trucks[j] += d[k];
			counts[j] ++;
			if (k == n) update(); 
            else Try(k+1);
			trucks[j] -= d[k];
			counts[j] --;
		}
	}
}

int main() {
	cin >> n >> K >> Q;
	for(int i = 1; i <= n; i ++) cin >> d[i];
	
	if (K == n) cout << 1;
	else {
		Try(1);
		cout << res/factorial(K) << endl;
	}

	return 0;
}