#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> vec;

void solve(){
    stack<int> pilha;
    ll maior = 0;
    int l;
    for(int i=0;i<=n;i++){
        while(!pilha.empty() && vec[i] <= vec[pilha.top()]){
            int aux = pilha.top();
            pilha.pop();
            if(pilha.empty()){
                l = -1;
            }
            else{
                l = pilha.top();
            }
            maior = max(maior, 1LL * (vec[aux] * (i-l-1)));
        }
        pilha.push(i);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    vec = vector<int> (n+1);
    for(int i=0;i<n;i++) cin>>vec[i];
    vec[n] = -1;
    solve();
    return 0;
}