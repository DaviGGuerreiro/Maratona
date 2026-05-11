#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<int,int> mapa;
int resposta;

template<typename T>
struct SegTree{
    int N;
    vector<T> seg;
    const T NEUTRAL = 0;
    SegTree(const vector<T> &vec) : N(vec.size()), seg(4*vec.size(), NEUTRAL){
        build(vec ,1 , 0, N-1);
    }
    T join(T v1, T v2){
        return v1 + v2;
    }
    void build(const vector<T> &vec, int v, int l, int r){  
        if(l == r){
            mapa[v] = vec[l];
            seg[v] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(vec, 2 * v, l, m);
        build(vec, 2 * v + 1, m+1, r);
        seg[v] = join(seg[2*v], seg[2*v + 1]);
        return;
    }
    void update(int v, int tl, int tr, int valor, int new_val){
        if(tl == tr){
            resposta = mapa[v];
            seg[v] = NEUTRAL;
            return;
        }
        int tm = (tl + tr)/2;
        if(seg[2*v] >= valor){
            update(2*v,tl,tm, valor , new_val);
        }
        else{
            update(2*v + 1,tm+1,tr, valor - seg[2 * v] , new_val);
        }
        seg[v] = join(seg[2*v], seg[2*v + 1]);
        return;
    }
    T query(int v, int L, int R, int l, int r){
        if(L > r || R < l) return NEUTRAL;
        if(L >= l && R <= r) return seg[v];
        int m = (L+R)/2;
        return join(query(2 * v, L, m, l, r), query(2*v +1, m+1,R, l, r));
    }
    T query(int l, int r){
        return query(1, 0, N-1, l, r);
    }
};

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    for(int i = 0; i <n ;i ++){
        cin>>vec[i];
    }
    auto tree = SegTree(vec);
    int valor;
    for(int i = 0; i < n; i++){
        cin>>valor;
        tree.update(1, 0, n-1, valor, 0);
        cout<<resposta<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}