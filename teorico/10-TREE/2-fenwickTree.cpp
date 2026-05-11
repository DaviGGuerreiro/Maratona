#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
    int n;
    vector<ll> bit;
    // Inicializa a BIT com tamanho n (1-based)
    BIT(int n) : n(n), bit(n + 1, 0) {}
    // Soma 'val' na posicao 'idx'
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) 
            bit[idx] += val;
    }
    // Retorna a soma do prefixo [1, idx]
    ll query(int idx) {
        ll sum = 0;
        for (; idx > 0; idx -= idx & -idx) 
            sum += bit[idx];
        return sum;
    }
    // Retorna a soma no intervalo [l, r]
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
};