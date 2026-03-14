#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> tree;
vector<int> vec;

int join(int l, int r){
    return l + r;
}

//buildando segtree
void build(int v, int tl, int tr){
    if(tl == tr){
        tree[v] = vec[tl];
    }
    else{
        int tm = (tl + tr)/2;
        build(2*v, tl, tm);
        build(2*v + 1, tm+1, tr);
        tree[v] = join(tree[v*2], tree[2*v + 1]);
    }
}

//update segtree
void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        tree[v] += new_val;
    }
    else{
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*v,tl,tm,pos,new_val);
        }
        else{
            update(2*v + 1,tm+1,tr,pos,new_val);
        }
        tree[v] = join(tree[v*2], tree[2*v + 1]); 
    }
}

int query(int v, int L, int R, int l, int r){
    if(R < l || L > r){
        return 0;
    }
    if(L <= l && r <= R){
        return tree[v];
    }
    int m = (l + r)/2;
    return join(query(2*v, L, R, l, m), query(2*v + 1, L, R, m+1 ,r));
}

void solve(){
    cin>>n;
    ll resposta = 0;
    tree = vector<int> (4*(n+1), 0);
    vec = vector<int> (n);
    for(int i = 0; i<n;i++){
        cin>>vec[i];
    }
    for(int i = 0; i<n; i++){
        resposta += query(1,vec[i],n,1,n);
        update(1,1,n,vec[i],1);
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}