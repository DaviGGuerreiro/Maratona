#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 2e5 + 5;
int vetor [mx];
ll tree[mx*4];

void build(int v, int tl, int tr){
    if(tl == tr){
        tree[v] = vetor[tl];
    }
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v + 1,tm+1, tr);
        tree[v] = tree[2*v] + tree[2*v+1];
    }
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        tree[v] = new_val;
    }
    else{
        int tm = (tl+tr)/2;
        if(pos<=tm){
            update(2*v,tl,tm,pos,new_val);
        }
        else{
            update(2*v + 1,tm+1,tr,pos,new_val);
        }
        tree[v] = tree[2*v] + tree[2*v + 1];
    }
}

ll sum(int v, int tl, int tr, int l, int r){
    if(r<l){
        return 0;
    }
    if(r == tr && l == tl){
        return tree[v];
    }
    else{
        int tm = (tl+tr)/2;
        return sum(2*v, tl, tm, l, min(r, tm)) + sum(2*v+1, tm+1, tr, max(l, tm+1), r);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    cin>>t>>n;
    for(int i=0;i<t;i++){
        cin>>vetor[i];   
    }
    build(1, 0, t-1);
    int q;
    ll a, b;
    ll r;
    while(n--){
        cin>>q>>a>>b;
        if(q == 1){
            update(1, 0, t-1, a-1, b);
        }
        else{
            r = sum(1,0,t-1,a-1, b-1);
            cout<<r<<'\n';
        }
    }

    return 0;
}