#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    int aux;
    long long resposta = 0;
    long long minimo = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>aux;
        resposta = resposta + aux;
        if(minimo > resposta ){
            minimo = resposta;
        }
    }
    cout<<-minimo<<'\n';

    return 0;
}