#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct SegTree{
    int N;
    vector<T> Seg;
    const T NEUTRAL = 0;
    SegTree(const vector<T> &vec) : N(vec.size()), Seg(4*vec.size(), NEUTRAL){
        build(vec, 1, 0, N-1);
    }
    T join(T v1, T v2){
        return v1 + v2;
    }
    void build(const vector<T> &vec, int v, int l, int r){
        if(l == r){
            Seg[v] = vec[l];
            return;
        }
        int m = (l + r)/2;
        build(vec, 2 * v, l, m);
        build(vec, 2 * v + 1, m+1, r);
        Seg[v] = join(Seg[2*v], Seg[2*v + 1]);
    }
    void update(int v, int tl, int tr, int pos, int val){
        if(tl == tr){
            Seg[v] = val;
            return;
        }
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2 * v, tl, tm, pos, val);
        }
        else{
            update(2 * v + 1, tm+1, tr, pos, val);
        }
        Seg[v] = join(Seg[2*v], Seg[2 * v + 1]);
    }
    T query(int v, int L, int R, int l, int r){
        if(L > r || R < l) return NEUTRAL;
        if(L >= l && R <= r){
            return Seg[v];
        }
        int m = (L + R)/2;
        return join(query(2*v,L,m,l,r), query(2*v + 1, m+1, R, l, r));
    }
    T query(int l, int r){
        return query(1, 0, N-1, l, r);
    }
};

void solve(){
    int n, q; cin>>n>>q;
    vector<ll> vec (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    auto tree = SegTree(vec);
    int tipo, a, b;
    for(int i = 0; i<q; i++){
        cin>>tipo>>a>>b;
        if(tipo == 1){
            a--;
            tree.update(1, 0, n-1, a, b);
        }
        else{
            a--; b--;
            ll soma = tree.query(a,b);
            cout<<soma<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}