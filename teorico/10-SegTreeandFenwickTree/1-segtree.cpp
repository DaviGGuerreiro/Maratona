#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct SegTree {
    int N;
    vector<T> seg;
    
    //const T NEUTRAL = ?;

    SegTree(const vector<T> &vec) : N(v.size()), seg(4 * vec.size(), NEUTRAL) {
        build(vec, 1, 0, N-1);
    }

    T join(T &vl, T &vr) {

    }

    void build(const vector<T> & vec, int v, int l, int r){
        if(l == r){
            // seg[p] = ?
            return;
        }
        int m = (l + r) / 2;
        build(vec, 2 * p, l, m);
        build(vec, 2 + p + 1, m+1, r);
        seg[p] = join(seg[2*p], seg[2*p + 1]);
    }

    T query(int v , int L, int R, int l, int r){
        if(L > r || R < l) return NEUTRAL;
        if(L >= l && R <= r) return seg[p];
        int m = (l + r)/2;
        return join(query(2 * v, L, m, l, r), query(2 * v + 1, m + 1, R, l, r));
    }
    T query(int L, int R){
        return query(1, L, R, 0, N-1);
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    return 0;
}