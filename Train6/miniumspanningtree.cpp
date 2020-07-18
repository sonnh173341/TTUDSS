#include<bits/stdc++.h>
using namespace std;
const int N = 100010 ;

int n,m;
vector<int> x[N];
struct edge{
	int v1, v2, cost;
};
vector<edge> l;
void input(){
	l.reserve(m);
	cin >> n >>m;
	for(int i = 0; i < m; i ++){
		int a,b,c; cin >> a >>b >>c;
		l.push_back(edge{a, b, c});
	}
}
bool check(edge const &e1, edge const &e2){
	return e1.cost < e2.cost;
}
vector<int>z;
bool checkIn(int u){
	for(int v : z){
		if(v == u) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	input();
	cin >> n >> m;
	sort(l.begin(), l.end(), check);
	for(int i = 0; i < m; i++){
		cout << l[i].v1 << " "<< l[i].v2 << " "<< l[i].cost << endl;
	}
	int ans = 0;
	int dem = 0;
	for(int i = 0; i < m; i++){
		if(!checkIn(l[i].v1) && !checkIn(l[i].v2)) continue; 
		dem ++;
		
		ans += l[i].cost;
		if(!checkIn(l[i].v1)) z.push_back(l[i].v2);
		else if(!checkIn(l[i].v2)) z.push_back(l[i].v1);
		else{
			z.push_back(l[i].v2);
			z.push_back(l[i].v1);
		}
		if(dem == n-1) break;
	}
	cout << ans;
	cout << endl;
	return 0;
}