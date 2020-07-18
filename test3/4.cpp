#include<bits/stdc++.h>
 
using namespace std;
 
struct edge {
	int v1, v2, cost, latency;
};
vector<edge> e;
vector<vector<int>> ll;
int N, M, s, L;
int m;
 
vector<int> a;
 
bool next_comb(int n)
{
	int index = m - 1;
	while(index >= 0 && a[index] == n - m + index) index--;
	if(index < 0) return false;
	a[index]++;
	for(int i = index + 1; i < m; i++) a[i] = a[i - 1] + 1;
	return true;
}
 
int calc(vector<edge> const & e)
{
	int res = 0;
	for(int i = 0; i < e.size(); i++) res += e[i].cost;
	queue<int> q;
	q.push(s);
	vector<int> visit(N);
	vector<int> adj[N];
	vector<int> lat(N);
	lat[s] = 0;
	for(int i = 0; i < e.size(); i++)
	{
		adj[e[i].v1].push_back(e[i].v2);
		adj[e[i].v2].push_back(e[i].v1);
	}
	while(q.size())
	{
		int cur = q.front();
		q.pop();
		visit[cur] = 1;
		if(lat[cur] > L) return INT_MAX;
		for(int i = 0; i < adj[cur].size(); i++)
		{
			if(!visit[adj[cur][i]])
			{
				int next = adj[cur][i];
				lat[next] = lat[cur] + ll[next][cur];
				q.push(next);
			}
		}
	}
	for(int i = 0; i < N; i++)
	{
		if(lat[i] > L) return INT_MAX;
		if(!visit[i]) return INT_MAX;
	}
	return res;
}
 
int main()
{
	cin >> N >> M >> s >> L;
	s--;
	ll.resize(N);
	for(int i = 0; i < N; i++) ll[i].resize(N);
	e.reserve(M);
	for(int i = 0; i < M; i++)
	{
		int u, v, c, l;
		cin >> u >> v >> c >> l;
		u--;
		v--;
		if(l <= L)
		{
			e.push_back(edge{u, v, c, l});
			ll[u][v] = l;
			ll[v][u] = l;
		}
	}
	m = M - (N - 1);
 
	int res = INT_MAX;
 
	for(int i = 0; i < m; i++) a.push_back(i);
	do
	{
		auto e1 = e;
		for(int i = m - 1; i >= 0; i--) e1.erase(e1.begin() + a[i]);
		res = min(res, calc(e1));
	}while(next_comb(M));
	if(res != INT_MAX) cout << res << endl;
	else cout << -1 << endl;
}