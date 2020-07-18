#include<bits/stdc++.h>
using namespace std;
const int n = 100010;
const int ch = 26;
const int m = 20;

struct Trie{
    int cnt[n*m];
    int child[n*m][ch];
    int num = 1;

    void add(string u){
        int curNode = 1;
        for(char v : u){
            int id = v - 'a';
            if(!child[curNode][id]) child[curNode][id] = ++num;
            curNode = child[curNode][id];
        }
        cnt[curNode] ++ ;
    }
    
    int find(string u){
        int curNode = 1;
        for(char v : u){
            int id = v - 'a';
            if(!child[curNode][id]){
                return 0;
            }
            curNode = child[curNode][id];
        }
        return cnt[curNode];
    }
};
Trie t;
void input(){
    int k; cin >> k;

    for(int i =1 ;i <=k; i++){
        int op; string u; cin >>op >> u;
        if(op == 1) t.add(u);
        else cout << t.find(u) <<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    return 0;
}