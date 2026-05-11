#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll norm(ll a){
    return (a % MOD + MOD) % MOD;
}
ll modmul(ll a, ll b){
    return (norm(a) * norm(b)) % MOD;
}
ll modsum(ll a, ll b){
    return (norm(a) + norm(b)) % MOD;
}

template<typename T>
struct SegTree{
    const T NEUTRAL = 0;
    int N;
    vector<pair<T,T>> seg; vector<T> lazy;
    SegTree(const vector<T> &vec) : N(vec.size()), seg(4 * vec.size(), {NEUTRAL,NEUTRAL}), lazy(4 * vec.size(), NEUTRAL){
        build(vec, 1, 0, N-1);
    }
    pair<T,T> join(pair<T,T> v1, pair<T,T> v2){
        return {modsum(v1.first,v2.first), modsum(v1.second,v2.second)};
    }
    void build(const vector<T> &vec, int v, int l, int r){
        if(l == r){
            seg[v] = {modmul(vec[l], vec[l]), vec[l]};
            return;
        }
        int m = (l + r)/2;
        build(vec, 2*v, l, m);
        build(vec, 2 * v + 1, m+1, r);
        seg[v] = join(seg[2*v], seg[2*v + 1]);
        return;
    }
    void push(int v, int L, int R) {
        if(lazy[v] != 0){
            ll tamanho = R - L + 1;
            ll p1 = modmul(tamanho,(modmul(lazy[v],lazy[v])));
            ll p2 = modmul(modmul(lazy[v],(seg[v].second)),2);
            ll p3 = modsum(p1, p2);
            seg[v].first = modsum(seg[v].first,p3);
            seg[v].second = modsum(seg[v].second,(modmul(tamanho,lazy[v])));
            if(L != R){
                lazy[2*v] = modsum(lazy[2*v],lazy[v]);
                lazy[2*v + 1] = modsum(lazy[2*v + 1],lazy[v]);
            }
            lazy[v] = 0;
        }
    }
    void updateRange(int v, int L, int R, int l, int r, ll val){
        push(v,L,R);
        if(L > r || R < l) return;
        if(L >= l && R <= r){
            lazy[v] = modsum(lazy[v],val);
            push(v,L,R);
            return;
        }
        int m = (L + R)/2;
        updateRange(2 * v, L, m, l, r, val);
        updateRange(2 * v + 1, m+1, R, l, r, val);
        seg[v] = join(seg[2* v], seg[2 * v + 1]);
    }
    pair<T,T> query(int v, int L, int R, int l, int r){
        push(v,L,R);
        if(L > r || R < l) return {NEUTRAL,NEUTRAL};
        if(L >= l && R <= r) return seg[v];
        int m = (L + R)/2;
        return join(query(2 * v, L, m, l, r), query(2 * v + 1, m+1, R, l, r));
    }
    pair<T,T> query(int l, int r){
        return query(1, 0, N-1, l, r);
    }
};

void solve(){
    int n, q; cin>>n>>q;
    vector<ll> vec (n);
    pair<ll,ll> resposta;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    auto tree = SegTree(vec);
    char t;
    ll l,r,x;
    for(int i = 0; i<q; i++){
        cin>>t;
        if(t == 'u'){
            cin>>l>>r>>x; l--; r--; x = norm(x);
            tree.updateRange(1, 0, n-1, l, r, x);
        }
        else if(t =='q'){
            cin>>l>>r; l--; r--;
            resposta = tree.query(l, r); resposta.first = resposta.first % MOD;
            cout<<resposta.first<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}