#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> arvore;
vector<ll> valores;

// euler tour
vector<int> tin, tout;
int timer = 0;
vector<ll> flat_array;

// Os casos que euler tour pura funciona:
// Muitas queries e nenhuma atualizacao
// Muitas atualizacoes poucas queries


void euler_tour(int node, int prev){
    tin[node] = timer;
    flat_array[timer] = valores[node];
    timer++;
    for(int it : arvore[node]){
        if(it != prev) euler_tour(it, node);
    }
    tout[node] = timer;
}

template<typename T>
struct SegTree {
    int N;
    const T NEUTRAL = 0;
    vector<T> seg;
    SegTree(const vector<T> &vec) : N(vec.size()), seg(4 * vec.size(), NEUTRAL) {
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
    void update(int v, int tl, int tr, int pos, T new_val){
        if(tl == tr){
            seg[v] = new_val;
            return;
        }
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*v,tl,tm,pos,new_val);
        }
        else{
            update(2*v + 1,tm+1,tr,pos,new_val);
        }
        seg[v] = join(seg[2*v], seg[2*v + 1]);
    }
    T query(int v, int L, int R, int l, int r){
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
    int n,q; cin>>n>>q;
    arvore = vector<vector<int>> (n+1); valores = vector<ll> (n+1);
    tin = vector<int> (n+1); tout = vector<int> (n+1);
    flat_array = vector<ll> (n);
    int a, b;
    for(int i = 1; i<=n; i++){
        cin>>valores[i];
    }
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
    }
    euler_tour(1, 0);
    SegTree<ll> Tree(flat_array);
    int tipo;
    for(int i = 0; i<q; i++){
        cin>>tipo;
        if(tipo == 1){
            cin>>a>>b;
            Tree.update(1, 0, n-1, tin[a], b);
        }
        else{
            cin>>a;
            cout<<Tree.query(tin[a],tout[a]-1)<<'\n';
        }
    }
    return 0;
}