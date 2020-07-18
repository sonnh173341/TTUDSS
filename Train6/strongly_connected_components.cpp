#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 5;
vector<int> v[NMAX];
bool visited[NMAX], del[NMAX];
int low[NMAX], num[NMAX];
int t = 0;
int res = 0;
int s[NMAX], top = 0;

void push(int u) {
	s[top++] = u;
}

int pop() {
	return s[--top];
}

void dfs(int u) {
	num[u] = ++t;
	low[u] = num[u];
	visited[u] = 1;
	push(u);
	for(int x : v[u]){
		if (!del[x]) {
			if (visited[x]) {
				low[u] = min(low[u], num[x]);
			} else {
				dfs(x);
				low[u] = min(low[u], low[x]);
			}
		}	
	}
	
	if (low[u] == num[u]) {
		res++;
		while (true) {
			int x = pop();
			del[x] = 1;
			if (x == u) break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		v[t1].push_back(t2);
	}
	
	memset(visited, 0, sizeof(visited));
	memset(del, 0, sizeof(del));
	for (int i = 1; i <= n; i++) {
		if (!del[i]) {
			dfs(i);
		}
	}
	
	cout << res << endl;
}