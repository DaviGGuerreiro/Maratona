#include<bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

//pode gerar ints ou doubles, basta mudar o parametro do template
long long uniform(long long l, long long r){
    uniform_int_distribution<long long> uid(l, r);
    return uid(rng);
}

void solve(){
    int n, q; cin>>n;
    vector<ll> a (n);
    vector<ll> b (n);
    for(int i= 0;i<n;i++){
        cin>>a[i];
    }
    for(int i= 0;i<n;i++){
        cin>>b[i];
    }

    map<long long, long long> valor;
    map<long long, long long> valorB;
    for(auto num : a){
        if(!valor.count(num)){
            valor[num] = uniform(1, 1e18);
        }
    }
    for(auto num : b){
        if(!valor.count(num)){
            valor[num] = uniform(1, 1e18);
        }
    }
    
    vector<ll> prefixoA (n+1);
    vector<ll> prefixoB (n+1);
    set<ll> vistoA, vistoB;
    prefixoA[0] = 0; prefixoB[0] = 0;
    for(int i= 1; i<=n;i++){
        if(vistoA.find(a[i-1]) == vistoA.end()){
            prefixoA[i] = prefixoA[i-1] ^ valor[a[i-1]];
            vistoA.insert(a[i-1]);
        }
        else{
            prefixoA[i] = prefixoA[i-1];
        }
        
        if(vistoB.find(b[i-1]) == vistoB.end()){
            prefixoB[i] = prefixoB[i-1] ^ valor[b[i-1]];
            vistoB.insert(b[i-1]);
        }
        else{
            prefixoB[i] = prefixoB[i-1];
        }
    }
    cin>>q;
    int x, y;
    for(int i= 0;i<q;i++){
        cin>>x>>y;
        if(prefixoA[x] == prefixoB[y]){
            cout<<"Yes"<<'\n';
        }
        else{
            cout<<"No"<<'\n';
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}