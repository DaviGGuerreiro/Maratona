#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// A ideia principal é representar os valores da string como uma soma dos valores assossiados a cada caractere
// Hash(s) = (somátorio(i = 0 -> i = n-1) Si * k^(n-1-i)) % mod M; M e k primos.
// Como tratar colisões? dois valores darem um Mesmo Hash? Esse caso já é muito improvavel (1/M), mas existe Hash duplo!
// Hash simples M com 100.000 itens já fica muito provável.
static const ll P1 = 31;
static const ll P2 = 37;
static const ll M1 = 1e9 + 33;
static const ll M2 = 1e9 + 93;

const int MAXN = 100005; //tamanho maximo da string;
ll powers1[MAXN], powers2[MAXN];
ll prefix_hash1[MAXN], prefix_hash2[MAXN];

void calc_powers(int n) { //chamar antes de qualquer coisa
    powers1[0] = 1;
    powers2[0] = 1;
    for (int i = 1; i <= n; i++) {
        powers1[i] = (powers1[i - 1] * P1) % M1;
        powers2[i] = (powers2[i - 1] * P2) % M2;
    }
}

struct StringHash {
    vector<ll> prefix_hash1, prefix_hash2;
    StringHash(const vector<ll>& s) {
        int n = s.size();
        prefix_hash1.assign(n + 1, 0);
        prefix_hash2.assign(n + 1, 0);

        for(int i = 0; i < n; i++){
            ll val = s[i];
            prefix_hash1[i+1] = (prefix_hash1[i] * P1 + val) % M1;
            prefix_hash2[i+1] = (prefix_hash2[i] * P2 + val) % M2;
        }
    }
    pair<ll,ll> query(int i, int j) {
        int len = j - i + 1;
        ll h1 = (((prefix_hash1[j+1] - (prefix_hash1[i] * powers1[len]) % M1) % M1) + M1) % M1;
        ll h2 = (((prefix_hash2[j+1] - (prefix_hash2[i] * powers2[len]) % M2) % M2) + M2) % M2;
        return {h1, h2};
    }
};

//Hash de Sets--------------------------------------------------------------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

//pode gerar ints ou doubles, basta mudar o parametro do template
long long uniform(long long l, long long r){
    uniform_int_distribution<long long> uid(l, r);
    return uid(rng);
}

void setHash(){
    int n;
    vector<ll> input;
    map<long long, long long> valor;
    for(auto num : input){
        if(!valor.count(num)){
            valor[num] = uniform(1, 1e18);
        }
    }

    long long hsh = 0;
    for(int i = 0; i < n; i++){
        hsh ^= valor[input[i]];
    }
}
//-----------------------------------------------------------------------------------
//pi[i] e o tamanho do maior prefix da substring (0,i) que bate perfeitamente
//com o sufixo da mesma string
vector<int> Pi(string &t){ 
    vector<int> p(t.size(), 0);

    for(int i=1, j=0; i<t.size(); i++){
        while(j > 0 && t[j] != t[i]) j = p[j-1];
        if(t[j] == t[i]) j++;
        p[i] = j;
    }
    return p;
}