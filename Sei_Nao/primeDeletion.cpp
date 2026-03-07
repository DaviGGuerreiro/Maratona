#include<bits/stdc++.h>
using namespace std;

bool isPrime(int v){
    for(int i = 2; i * i <= v; i++){
        if(v%i == 0) return false;
    }
    return true;
}

void solve(){
    int num;
    cin>>num;
    vector<int> vec (9);
    int j = 1;
    for(int i=0;i<9;i++){
        vec[i] = (num/j)%10;
        j = j*10;
    }
    int valor;
    for(int mask = 0; mask < (1<<9); mask++){
        int tamanho = __builtin_popcount(mask);
        if(tamanho>=2){
            valor = 0;
            j = 1;
            for(int i = 0; i<9; i++){
                if(mask & (1<<i)){
                    valor += vec[i]*j;
                    j = j*10;
                }
            }
            if(isPrime(valor)){
                cout<<valor<<'\n';
                return;
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}