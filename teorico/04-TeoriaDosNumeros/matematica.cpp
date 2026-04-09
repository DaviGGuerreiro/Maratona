#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int n = 2e5 + 1;
const int MOD = 1e9 + 7;

vector<vector<int>> primos (n);
vector<bool> visitados (n, false);

vector<int> getdivisors(int n) {
    vector<int> divisors;
    for(int i = 1; i * i <= n; i++){
        if(n % 1 == 0){
            divisors.push_back(i);
            if(i != n/i) divisors.push_back(n/i);
        }
    }
    return divisors;
}

const int m = 1e7;
bool isPrime[m];

vector<int> crivo(){ // calcular todos os primos
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    vector<int> primes;
    for(int i = 2; i < m; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i + i; j < m; j += i){
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

void sieve(){ // calcula fatoracao prima de numeros (so numeros, sem quantidade)
    for(int i = 2; i<=n-1; i++){
        if(visitados[i]) continue;
        visitados[i] = true;
        for(int j = i; j<=n-1; j+=i){
            visitados[j] = true;
            primos[j].push_back(i);
        }
    }
}

void fact(ll& x){
    ll res = 1;
    for(int i = 2; i<= x; i++){
        res *= i;
        res = res % MOD;
    }
    x = res;
}

ll mod_add(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}
ll sub(ll a, ll b){
    return((a % MOD - b % MOD) + MOD) % MOD;
}
ll mod_mul(ll a, ll b){
    return(a % MOD * b % MOD) % MOD;
}

ll fexp(ll a, ll b){ // num a, primo b - 2 (1e9 + 7 - 2)
    ll ret = 1;
    while(b){
        if(b%2 == 1) ret = mod_mul(ret,a);
        a = mod_mul(a,a);
        b >>= 1;
    }
    return ret % MOD;
}

long double log7(ll w){ //trocar base
    return log(w)/log(7.0);
}
