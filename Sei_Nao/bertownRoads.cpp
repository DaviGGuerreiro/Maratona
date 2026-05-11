#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> vec;
vector<bool> vis;
queue<pair<int,int>> resposta;
bool flg;
int quantidade = 0;

void dfs(int x, int pai){
    quantidade++;
    vis[x] = true;
    flg = false;
    for(auto v : vec[x]){
        if(!vis[v]){
            resposta.push({x, v});
            flg = true;
            dfs(v, x);
            if(!flg) return;
        }
        else if(v != pai){
            flg = true;
        }
    }
    return;
}

void solve(){
    int m; cin>>n>>m;
    vec = vector<vector<int>> (n+1);
    vis = vector<bool> (n+1, false);
    int a, b;
    map<pair<int,int>, bool> mapa;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        mapa[{a,b}] = true;
        mapa[{b,a}] = true;
    }
    dfs(1,1);
    if(!flg || quantidade != n){
        cout<<0<<'\n';
        return;
    }
    while(!resposta.empty()){
        auto aux = resposta.front(); resposta.pop();
        cout<<aux.first<<' '<<aux.second<<'\n';
        mapa[{aux.first, aux.second}] = false;
        mapa[{aux.second, aux.first}] = false;
    }
    for(auto [k, v]: mapa){
        if(v){
            cout<<k.first<<' '<<k.second<<'\n';
            mapa[{k.second, k.first}] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}