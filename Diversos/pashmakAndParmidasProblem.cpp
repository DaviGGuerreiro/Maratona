#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> BIT;
vector<int> vec;

ll query(int x){
    int res = 0;
    while(x>0){
        res +=  BIT[x];
        x -= (x & -x);
    }
    return res;
}

void update(int x, int val){
    while(x <= n) {
        BIT[x] += val;
        x += (x & -x);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    BIT = vector<int> (n+1);
    vec = vector<int> (n);
    vector<int> vet (n,0);
    vector<int> vex (n,0);
    map<int,int> mapa1;
    map<int,int> mapa2;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    for(int i = 0; i<n; i++){
        mapa1[vec[i]]++;
        vet[i] = mapa1[vec[i]];
    }
    for(int i = n-1; i>=0; i--){
        mapa2[vec[i]]++;
        vex[i] = mapa2[vec[i]];
    }
    ll resposta = 0;
    for(int i = n-1; i>=0; i--){
        resposta += query(vet[i] - 1); //quantos caras a freq é menor que ele?
        update(vex[i], 1); //bota o ultimo
    }
    cout<<resposta;
    
    return 0;
}