#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll soma;
ll aux = 1e12;
vector<int> p;

void backtrack(ll somatorio, int pos){
    if(2*somatorio >=  soma){ //solucao completa e valida?
        aux = min(aux, 2*somatorio - soma);
        return;
    }

    for(int i=pos;i<n;i++){
        //b[pos] = 1;
        backtrack(somatorio + p[i], i+1);
        //b[pos] = 0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    soma = 0;
    int aux1;
    cin>>n;
    //vector<bool> b (n,false);
    for(int i=0;i<n;i++){
        cin>>aux1;
        p.push_back(aux1);
        soma = soma + p[i];
    }
    backtrack(0, 0);
    cout<<aux;

    return 0;
}