#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<int,int>>> arvore;
vector<int> valores;

int l, n;
vector<int> tin, tout;
vector<vector<int>> up;
int timer = 0;
vector<ll> flat_array;

bool is_ancestor(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

void dfs(int v, int p, int peso){
    tin[v] = ++timer;
    valores[v] = peso;
    flat_array[timer] = valores[v]; // tin
    up[v][0] = p;
    for(int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u : arvore[v]){
        if(u.first != p){
            dfs(u.first,v, u.second);
        } 
    }
    tout[v] = ++timer;
    flat_array[timer] = -valores[v]; // tout
}

int lca(int u, int v){
    if(is_ancestor(u,v)) return u;
    if(is_ancestor(v,u)) return v;
    for(int i = l; i >= 0; --i){
        if(!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

template<typename T>
struct SegTree {
    const T NEUTRAL = 0;
    int N;
    vector<T> seg;
    vector<T> lazy;
    SegTree(const vector<T> &vec) : N(vec.size()), seg(4 * vec.size(), NEUTRAL), lazy(4 * vec.size(), NEUTRAL) {
        build(vec, 1, 0, N-1);
    }
    T join(const T &vl, const T &vr) {
        return vl + vr; 
    }
    void build(const vector<T> & vec, int v, int l, int r){
        if(l == r){
            seg[v] = vec[l];
            return;
        }
        int m = (l + r) / 2;
        build(vec, 2 * v, l, m);
        build(vec, 2 * v + 1, m+1, r);
        seg[v] = join(seg[2*v], seg[2*v + 1]);
    }
    void push(int v, int L, int R) {
        if(lazy[v] != 0){
            seg[v] += lazy[v];
            if(L != R){
                lazy[2*v] += lazy[v];
                lazy[2*v + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }
    void updateRange(int v, int L, int R, int l, int r, ll val){
        push(v,L,R);
        if(L > r || R < l) return;
        if(L >= l && R <= r){
            lazy[v] += val;
            push(v,L,R);
            return;
        }
        int m = (L + R)/2;
        updateRange(2 * v, L, m, l, r, val);
        updateRange(2 * v + 1, m+1, R, l, r, val);
        seg[v] = join(seg[2* v], seg[2 * v + 1]);
    }
    T query(int v, int L, int R, int l, int r){
        push(v,L,R);
        if(L > r || R < l) return NEUTRAL;
        if(L >= l && R <= r) return seg[v];
        int m = (L+R)/2;
        return join(query(2 * v, L, m, l, r), query(2*v +1, m+1,R, l, r));
    }
    T query(int L, int R){
        return query(1, 0, N-1, L, R);
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    l = ceil(log2(n));
    arvore = vector<vector<pair<int,int>>> (n+1);
    valores = vector<int> (n+1);
    tin = vector<int> (n+1); tout = vector<int> (n+1);
    up = vector<vector<int>> (n+1, vector<int> (l+1));
    flat_array = vector<ll> (2 * n + 1);
    int a, b, c;
    vector<tuple<int,int,int>> arestas (n);
    for(int i = 0; i<n-1; i++){
        cin>>a>>b>>c;
        arvore[a].push_back({b,c});
        arvore[b].push_back({a,c});
        arestas[i+1] = make_tuple(a,b,c);
    }
    dfs(1, 1, 0);
    SegTree<ll> Tree(flat_array);
    int tipo;
    ll resposta, dif;
    int no_upg;
    int q;
    cin>>q;
    for(int i = 0; i<q; i++){
        cin>>tipo;
        if(tipo == 1){
            cin>>a>>b;
            dif = b - get<2>(arestas[a]);
            get<2>(arestas[a]) = b;
            if(tin[get<0>(arestas[a])] > tin[get<1>(arestas[a])]){ // o mais fundo que tem o valor
                no_upg = get<0>(arestas[a]);
            }
            else{
                no_upg = get<1>(arestas[a]);
            }
            Tree.updateRange(1, 0, Tree.N - 1, tin[no_upg], tin[no_upg], dif);
            Tree.updateRange(1, 0, Tree.N - 1, tout[no_upg], tout[no_upg], -dif);
        }
        else{
            cin>>a>>b; 
            resposta = Tree.query(1, tin[a]);
            resposta += Tree.query(1, tin[b]);
            int comum = lca(a,b);
            resposta -= (Tree.query(1, tin[comum]) * 2);
            cout<<resposta<<'\n';
        }
    }
    return 0;
}