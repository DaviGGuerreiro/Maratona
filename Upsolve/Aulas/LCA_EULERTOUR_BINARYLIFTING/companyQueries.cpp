#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> arvore;

// binaryLigting
vector<int> tin, tout;
vector<vector<int>> up;
int timer = 0; int l, n;

bool is_ancestor(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int u : arvore[v]){
        if(u != p) dfs(u,v);
    }
    tout[v] = ++timer;
}

int lca(int u, int v){
    if(is_ancestor(u,v)) return u;
    if(is_ancestor(v,u)) return v;
    for(int i = l; i >= 0; --i){
        if(!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0); int q;
    cin>>n>>q;
    arvore = vector<vector<int>> (n+1);
    tin = vector<int> (n+1); tout = vector<int> (n+1); l = ceil(log2(n));
    up = vector<vector<int>> (n+1, vector<int> (l + 1));
    int a, b;
    for(int i = 2; i<=n; i++){
        cin>>a;
        arvore[i].push_back(a);
        arvore[a].push_back(i);
    }
    dfs(1,1);
    while(q--){
       cin>>a>>b;
       cout<<lca(a,b)<<'\n';
    }
    
    return 0;
}