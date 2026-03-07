#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int m = 1e9 + 7;
vector<vector<int>> vec;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vec = vector<vector<int>> (n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
    vector<ll> dp (1<<n, 0);
    dp[0] = 1;
    for(int bitmask = 0; bitmask< 1<<n; bitmask++){ //rodando por toda combinação 
        if(!dp[bitmask] == 0){ //se o arranjo for viavel
            int i = __builtin_popcount(bitmask); //quantas mulheres foram ligadas?
            if(i != n){ //se não todas
                for(int j=0; j<n; j++){ //verifico dos homens quem pode se ligar a alguma que sobra
                    if(vec[i][j] == 1 && !(bitmask & 1<<j)){ //e se ela esta disponivel para ele
                        int prox = bitmask | (1<<j);
                        dp[prox] = (dp[prox] + dp[bitmask]) % m; //então a posição onde aquela mulher se liga a ele logo apos a posição anterior é somada
                    }
                }
            }
        }
        //assim um arranjo é a soma de todos os que chegam a ele, e compõe todos os outros que derivam dele.
    }
    cout << dp[(1<<n)-1];
    return 0;
}