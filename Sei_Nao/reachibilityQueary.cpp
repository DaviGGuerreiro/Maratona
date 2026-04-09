#include<bits/stdc++.h>
using namespace std;
int n,q;
int const num = 2e5 + 1;
int pai[num];
int sz[num];
int origem[num];

int join(int u){
    if(u == pai[u]) return u;
    return pai[u] = join(pai[u]);
}

void unite(int u, int v){
    u = join(u);
    v = join(v);

    if(v == u) return;
    if(sz[u]<sz[v]) swap(u,v);

    pai[v] = u;
    origem[u] += origem[v];
    sz[u] += sz[v];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>q;
    vector<bool> cor (n+1,false);
    for(int i=1;i<=n;i++){
        pai[i] = i;
        sz[i] = 1;
        origem[i] = 0;
        cor[i] = false;
    }
    int a,b,c;
    while(q--){
        cin>>a;
        if(a == 1){
            cin>>b>>c;
            unite(b,c);
        }
        else if(a == 2){
            cin>>b;
            cor[b] = !cor[b];
            if(cor[b]){
                origem[join(b)]++;
            }
            else{
                origem[join(b)]--;
            }
        }
        else{
            cin>>b;
            if(origem[join(b)] > 0){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
    return 0;
}