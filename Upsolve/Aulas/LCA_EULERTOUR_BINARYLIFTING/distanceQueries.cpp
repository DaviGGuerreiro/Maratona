#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> arvore;

// binaryLigting
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> depth;
int timer = 0; int l, n;

bool is_ancestor(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

void dfs(int v, int p, int dist){
    depth[v] = dist; 
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int u : arvore[v]){
        if(u != p) dfs(u,v,dist+1);
    }
    tout[v] = ++timer;
}

int kth_anc(int node, int k){
    int cur = node;
    for(int i = 0; (1<<i)<=k; i++){
        if((1<<i) & k) cur = up[cur][i];
    }
    return cur;
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
    arvore = vector<vector<int>> (n+1); depth = vector<int> (n+1,0);
    tin = vector<int> (n+1); tout = vector<int> (n+1); l = ceil(log2(n));
    up = vector<vector<int>> (n+1, vector<int> (l + 1));
    int a, b;
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
    }
    dfs(1,1,0);
    int distancia;
    while(q--){
        cin>>a>>b;
        distancia = depth[a] + depth[b] - 2*depth[(lca(a,b))];
        cout<<distancia<<'\n';
    }
    return 0;
}