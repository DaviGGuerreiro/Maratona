#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;
vector<vector<int>> arvore;
vector<ll> valores;

// binaryLigting
vector<int> tin, tout;
vector<vector<int>> up;
int timer = 0; int l, n;

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

int kth_anc(int node, int k){
    int cur = node;
    for(int i = 0; (1<<i)<=k; i++){
        if((1<<i) & k) cur = up[cur][i];
    }
    return cur;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    arvore = vector<vector<int>> (n+1); valores = vector<ll> (n+1);
    tin = vector<int> (n+1); tout = vector<int> (n+1); l = ceil(log2(n));
    up = vector<vector<int>> (n+1, vector<int> (l + 1));
    int a, b;
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
    }
    // for(int i = 1; i<=n; i++){
    //     cin>>valores[i];
    // }
    dfs(1,1);
    cout<<(kth_anc(8,4));
    return 0;
}