#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void binSearch(vector<ll>& vec, ll k, int l, int r){
    int mid;
    while(r >= l){
        mid = l + ((r-l)/2);
        if(vec[mid] > k){
            r = mid - 1;
        }
        else if(vec[mid] <= k){
            l = mid + 1;
        }
    }
    cout<<l<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, i;
    ll k;
    cin>>n>>k;
    vector<int> direita (n);
    vector<int> esquerda (n);
    for(i=0;i<n;i++){
        cin>>direita[i];
    }
    sort(direita.begin(),direita.end());
    for(i=0;i<n;i++){
        cin>>esquerda[i];
    }
    sort(esquerda.begin(),esquerda.end());

    vector<ll> resposta (n);
    ll aux=0;
    for(i=0;i<n;i++){
        aux = aux + direita[i] + esquerda[i];
        resposta[i] = aux;
    }
    binSearch(resposta,k,0,n-1);
    return 0;
}