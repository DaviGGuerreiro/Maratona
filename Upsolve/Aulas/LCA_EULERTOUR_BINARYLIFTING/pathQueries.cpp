#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> arvore;
vector<int> valores;

int l, n;
vector<int> tin, tout;
int timer = 0;
vector<ll> flat_array;

void dfs(int v, int p){
    tin[v] = ++timer;
    flat_array[timer] = valores[v]; // tin
    for(auto u : arvore[v]){
        if(u != p){
            dfs(u,v);
        } 
    }
    tout[v] = ++timer;
    flat_array[timer] = -valores[v]; // tout
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
    ios::sync_with_stdio(false);cin.tie(0); int q;
    cin>>n>>q;
    arvore = vector<vector<int>> (n+1);
    valores = vector<int> (n+1,0);
    tin = vector<int> (n+1); tout = vector<int> (n+1);
    flat_array = vector<ll> (2 * n + 1);
    int a, b;
    for(int i = 1; i<=n; i++){
        cin>>valores[i];
    }
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
    }
    dfs(1, 1);
    SegTree<ll> Tree(flat_array);
    int tipo;
    ll resposta, dif;
    int no_upg;
    for(int i = 0; i<q; i++){
        cin>>tipo;
        if(tipo == 1){
            cin>>a>>b;
            dif = b - valores[a];
            valores[a] = b;
            no_upg = a;
            Tree.updateRange(1, 0, Tree.N - 1, tin[no_upg], tin[no_upg], dif);
            Tree.updateRange(1, 0, Tree.N - 1, tout[no_upg], tout[no_upg], -dif);
        }
        else{
            cin>>a; 
            resposta = Tree.query(1, tin[a]);
            cout<<resposta<<'\n';
        }
    }
    return 0;
}