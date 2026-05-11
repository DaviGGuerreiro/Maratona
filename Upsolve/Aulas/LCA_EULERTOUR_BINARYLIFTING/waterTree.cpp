#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> arvore;
vector<int> pai;
int l, n;
vector<int> tin, tout;
int timer = 0;
vector<bool> flat_array;

void euler_tour(int node, int prev){
    pai[node] = prev;
    tin[node] = timer;
    flat_array[timer] = false;
    timer++;
    for(int it : arvore[node]){
        if(it != prev) euler_tour(it, node);
    }
    tout[node] = timer;
}

template<typename T>
struct SegTree {
    const T NEUTRAL = true;
    int N;
    vector<T> seg;
    vector<pair<T,T>> lazy;
    SegTree(const vector<T> &vec) : N(vec.size()), seg(4 * vec.size(), NEUTRAL), lazy(4 * vec.size(), {NEUTRAL,false}) {
        build(vec, 1, 0, N-1);
    }
    T join(const T &vl, const T &vr) {
        return vl & vr; 
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
        if(lazy[v].second != false){
            seg[v] = lazy[v].first;
            if(L != R){
                lazy[2*v] = lazy[v];
                lazy[2*v + 1] = lazy[v];
            }
            lazy[v].second = false;
        }
    }
    void updateRange(int v, int L, int R, int l, int r, bool val){
        push(v,L,R);
        if(L > r || R < l) return;
        if(L >= l && R <= r){
            lazy[v].first = val;
            lazy[v].second = true;
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
    cin>>n;
    arvore = vector<vector<int>> (n+1);
    tin = vector<int> (n+1); tout = vector<int> (n+1);
    flat_array = vector<bool> (n);
    pai = vector<int> (n+1);
    int a, b;
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
    }
    euler_tour(1, 1);
    SegTree<bool> Tree(flat_array);
    int tipo;
    cin>>q;
    for(int i = 0; i<q; i++){
        cin>>tipo;
        if(tipo == 1){
            cin>>a;
            if(a != 1 && Tree.query(tin[pai[a]], tout[pai[a]]-1) == false){
                Tree.updateRange(1, 0, Tree.N - 1, tin[a], tout[a] - 1, true);
                Tree.updateRange(1,0, Tree.N - 1, tin[pai[a]], tin[pai[a]], false);
            }
            else{
                Tree.updateRange(1, 0, Tree.N - 1, tin[a], tout[a] - 1, true);
            }
        }
        else if(tipo == 2){
            cin>>a; 
            Tree.updateRange(1,0, Tree.N - 1, tin[a], tin[a], false);
        }
        else{
            cin>>a;
            cout<<Tree.query(tin[a],tout[a]-1)<<'\n';
        }
    }
    return 0;
}