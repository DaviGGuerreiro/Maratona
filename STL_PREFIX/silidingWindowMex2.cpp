#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, k;
    int aux;
    cin>>n>>k;
    set<int> conjunto;
    map<int, int> mapa;
    queue<int> fila;
    for(int i =0;i<=k;i++){
        conjunto.insert(i);
    }
    for(int i=0;i<k-1;i++){
        cin>>aux;
        fila.push(aux);
        mapa[aux]++;
        if(mapa[aux] == 1){
            if(conjunto.find(aux) != conjunto.end()){
                conjunto.erase(aux);
            }
        }
    }
    for(int i=0;i<n-k+1;i++){
        cin>>aux;
        fila.push(aux);
        if(i != 0){
            mapa[fila.front()]--;
            if(mapa[fila.front()] == 0){
                conjunto.insert(fila.front());
            } 
            fila.pop();
        }
        mapa[aux]++;
        if(mapa[aux] == 1){
            if(conjunto.find(aux) != conjunto.end()){
                conjunto.erase(aux);
            }
        }
        cout<<*conjunto.begin()<<' ';
    }

    return 0;
}