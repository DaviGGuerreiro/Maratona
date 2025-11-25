#include<bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;
int vetor[mx];
int tree[4*mx];

//buildando segtree
void build(int v, int tl, int tr){
    if(tl == tr){
        tree[v] = vetor[tl];
    }
    else{
        int tm = (tl + tr)/2;
        build(2*v, tl, tm);
        build(2*v + 1, tm+1, tr);
        tree[v] = tree[v*2] + tree[2*v + 1];
    }
}

//update segtree
void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        tree[v] = new_val;
    }
    else{
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*v,tl,tm,pos,new_val);
        }
        else{
            update(2*v + 1,tm+1,tr,pos,new_val);
        }
        tree[v] = tree[v*2] + tree[2*v + 1]; 
    }
}

int sum(int v, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }
    if(l == tl && r == tr){
        return tree[v];
    }
    int tm = (tl + tr)/2;
    return sum(2*v, tl, tm, l, min(r, tm)) + sum(2*v + 1, tm+1, tr, max(l, tm+1), r);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vetor[i];
    }
    build(1, 0, n-1);
    return 0;
}