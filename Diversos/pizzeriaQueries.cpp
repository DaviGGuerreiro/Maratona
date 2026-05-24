#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int,int>> tree;
vector<int> vec;
vector<int> v;

pair<int,int> join(pair<int,int> l, pair<int,int> r){
    int a, b;
    a = min(l.first, r.first);
    b = min(l.second, r.second);
    return {a,b};
}

//buildando segtree
void build(int v, int tl, int tr){
    if(tl == tr){
        tree[v] = {vec[tl] - tl, vec[tl] + tl};
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
        tree[v] = {new_val - tl, new_val + tl};
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

pair<int,int> query(int v, int L, int R, int l, int r){
    if(R < l || L > r){
        return {1e9,1e9};
    }
    if(L <= l && r <= R){
        return tree[v];
    }
    int m = (l + r)/2;
    return join(query(2*v, L, R, l, m), query(2*v + 1, L, R, m+1 ,r));
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, q;
    cin>>n>>q;
    tree = vector<pair<int,int>> (4*n);
    vec = vector<int> (n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    build(1, 0, n-1);
    int tipo, x, y;
    for(int i = 0; i<q;i++){
        cin>>tipo;
        if(tipo == 1){
            cin>>x>>y;
            x--;
            update(1,0,n-1,x,y);
        }
        else{
            int r1 = 1e9; int r2 = 1e9;
            cin>>x;
            x--;
            pair<int, int> aux = query(1, 0, x, 0, n-1);
            r1 = aux.first + x;
            aux = query(1, x+1,n-1,0, n-1);
            r2 = aux.second - x;
            int resposta = min(r1,r2);
            cout<<resposta<<'\n';
        }
    }
    return 0;
}