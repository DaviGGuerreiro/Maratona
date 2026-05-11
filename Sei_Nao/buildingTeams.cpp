#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> vec;
vector<int> vis;
bool impossivel = false;

void dfs(int x, int time){
    vis[x] = time;
    int novo;
    if(time == 1) novo = 2;
    else novo = 1;
    for(auto v : vec[x]){
        if(vis[v] == 0){
            dfs(v, novo);
            if(impossivel) return;
        }
        else if(vis[v] == time){
            impossivel = true;
            return;
        }
    }
}

void solve(){
    int m; cin>>n>>m;
    vec = vector<vector<int>> (n+1);
    vis = vector<int> (n+1, 0);
    int a, b;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        if(vis[i] == 0){
            dfs(i, 1);
            if(impossivel){
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }
    for(int i = 1; i<=n; i++){
        cout<<vis[i]<<' ';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}