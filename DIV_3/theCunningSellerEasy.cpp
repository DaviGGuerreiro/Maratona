#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    ios::sync_with_stdio(false);cin.tie(0);
    int t, x;
    cin>>t;
    while(t--){
        cin>>x;
        int e=0;
        ll aux = 3;
        int quantidade=x;
        ll moedas=0;
        while(x!=0){
            if(x/aux >=1){
                e++;
                quantidade = x/aux;
                aux = aux*3;
            }
            else{
                moedas = moedas + quantidade*(pow(3, e-1)*(9+e));
                x = x - quantidade*aux/3;
                aux = aux/3;
                quantidade = x/aux;
                e--;
            }
        }
        cout<<moedas<<'\n';
    }

    return 0;
}