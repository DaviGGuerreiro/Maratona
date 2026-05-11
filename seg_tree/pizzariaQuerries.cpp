#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct SegTree{
    int N;
    vector<T> seg;
    const T NEUTRAL = make_pair(2e9,2e9);
    SegTree(const vector<T> &vec) : N(vec.size()), seg(4*vec.size(), NEUTRAL){
        build(vec ,1 , 0, N-1);
    }
    T join(T v1, T v2){
        return {min(v1.first ,v2.first), min(v1.second, v2.second)};
    }
    void build(const vector<T> &vec, int v, int l, int r){  
        if(l == r){
            seg[v] = vec[l];
            return;
        }
        int m = (l + r) / 2;
        build(vec, 2 * v, l, m);
        build(vec, 2 * v + 1, m+1, r);
        seg[v] = join(seg[2*v], seg[2*v + 1]);
        return;
    }
    void update(int v, int tl, int tr, int pos, int new_val){
        if(tl == tr){
            seg[v] = {new_val - tl, new_val + tl};
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


void solve(){
    int n, q; cin>>n>>q;
    vector<pair<ll,ll>> vec (n);
    for(int i = 0; i <n ;i ++){
        cin>>vec[i].first;
        vec[i].second = vec[i].first + i;
        vec[i].first -= i;
    }
    auto tree = SegTree(vec);
    ll tipo, a, b;
    for(int i = 0; i < q; i++){
        cin>>tipo;
        if(tipo == 1){
            cin>>a>>b; a--;
            tree.update(1, 0, n-1, a, b);
        }
        else{
            cin>>a; a--;
            ll esquerdo = tree.query(0, a).first + a;
            ll direito = tree.query(a, n-1).second - a;
            ll resposta = min(esquerdo, direito);
            cout<<resposta<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}