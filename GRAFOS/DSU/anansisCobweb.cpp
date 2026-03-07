#include<bits/stdc++.h>
using namespace std;
//tipos
using ll = long long;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
//loops
#define FOR(i,n) for(int i=0; i<(int)(n); i++)
#define FOR1(i,n) for(int i=1; i<=(int)(n); i++)
#define FORA(x,a) for(auto &x : a)
//Sorts
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
//debug
#define dbg(x) cerr << #x << " = " << x << "\n" 

//  ll aux = LLONG_MAX;
//  int a = INT_MAX;
int total;
int const n = 1e5;
int pai[n];
int sz[n];

int find(int u){
    if(u == pai[u]) return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;
    if(sz[u]<sz[v]) swap(u,v);
    total--;
    pai[v] = u;
    sz[u] = sz[u] + sz[v];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int num, m;
    int a, b;
    int q;
    vector<pii> vec;
    map<int,int> mapa;
    stack<int> pilha;
    cin>>num>>m;
    FOR(i,num+1){
        pai[i] = i;
        sz[i] = 1;
    } 
    FOR1(i,m){
        cin>>a>>b;
        vec.push_back({a,b});
    }
    cin>>q;
    while(q--){
        cin>>a;
        mapa[a-1] = -1;
        pilha.push(a-1);
    }
    
    total = num;
    FOR(i,m){
        if(mapa[i] != -1){
            join(vec[i].first,vec[i].second);
        }
    }
    stack<int> pilha2;
    int aux;
    while(!pilha.empty()){
        aux = pilha.top();
        pilha2.push(total);
        join(vec[aux].first,vec[aux].second);
        pilha.pop();
    }
    while(!pilha2.empty()){
        cout<<pilha2.top()<<" ";
        pilha2.pop();
    }

    return 0;
}