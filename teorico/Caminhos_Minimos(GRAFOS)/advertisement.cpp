#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll resposta;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    vector<ll> vec (n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    stack<ll> pilha;
    resposta = -1;
    ll aux;
    for(int i=0;i<=n;i++){
        if(i == n){
            aux = 0;
        }
        else{
            
        }
        while(!pilha.empty() && vec[i] < vec[pilha.top()]){

        }
        pilha.push(i);
    }
    cout<<resposta;

    
    return 0;
}