#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll modulo = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> vec (n);
    ll total = 0;
    ll resposta = 0;
    ll aux;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        total = total + vec[i];
    }
    for(int i=0;i<n;i++){
        total = total - vec[i];
        aux = total % modulo;
        aux = aux * vec[i];
        resposta += aux;
        resposta = resposta % modulo;
    }
    cout<<resposta;

    return 0;
}