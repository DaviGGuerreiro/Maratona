#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll solve(ll num, vector<int>& bits){
    ll resposta = 0;
    for(int j = 0; j < 30; j++){
        ll aux = 1<<j;
        if(!(num & aux)){
            resposta += aux*bits[j];
        }
        else{
            resposta += aux*(n-bits[j]);
        }
    }
    return resposta;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<int> bits (30,0);
        ll maximo = 0;
        cin>>n;
        vector<ll> vec (n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
            for(int j = 0; j < 30; j++){
                if(vec[i] & 1<<j){
                    bits[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            maximo = max(maximo,solve(vec[i], bits));
        }
        cout<<maximo<<'\n';
    }
    return 0;
}