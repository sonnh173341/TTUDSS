#include<bits/stdc++.h>
using namespace std;
const int n = 100010;
const int ch = 2;
const int m = 32;

struct Trie{
    int cnt[n*m];
    int child[n*m][ch];
    int num = 1;

    void add(int u){
        int curNode = 1;
        for (int i = m-1; i >= 0; i --){
            int id = u >> i & 1;
            if(!child[curNode][id]) child[curNode][id] = ++num;
            curNode = child[curNode][id];
        }
        cnt[curNode] ++ ;
    }
    
    void dfs(int curNode, int curNum){
        for (int i = 1; i <= cnt[curNode]; i++){
            cout << curNum << " ";
        }
         for(int i = 0; i < ch; i++){
                if(!child[curNode][i]) continue;
                dfs(child[curNode][i], curNum*2 + i);  
        }
    }
};
Trie t;
void input(){
    int k; cin >> k;

    for(int i =1 ;i <=k; i++){
        int a; cin >> a;
        t.add(a);
    }
    t.dfs(1, 0);
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    return 0;
}