#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, k;
    cin>>n>>k;
    vector<ll> vec(n);
    ll a, b, c, x;
    cin>>x>>a>>b>>c;
    ll aux = x;
    for(int i=0;i<n;i++){
        vec[i] = aux;
        x = (a * x + b) % c;
        aux = aux + x;
    }
    aux = 0;
    ll dir, esq = 0;
    int j = 0;
    for(int i=k;i<n+1;i++){
        dir = vec[i-1] - esq;
        esq = vec[j];
        j++;
        aux = aux xor dir;
    }
    cout<<aux<<'\n';
    return 0;
}