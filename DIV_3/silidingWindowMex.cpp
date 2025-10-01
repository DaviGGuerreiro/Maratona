#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    size_t k;
    cin>>n>>k;
    int aux;
    vector<int> vec (2e5, 0);
    set<int> buracos;
    queue<int> fila;
    for(int i=0;i<n;i++){
        cin>>aux;
        if(fila.size() < k - 1){
            fila.push(aux);
            if(aux < 2e5){
                vec[aux]++;
            }
        }
        else if(fila.size() == k-1){
            fila.push(aux);
            if(aux < 2e5){
                vec[aux]++;
            }
            for(int j = 0;j<2e5;j++){
                if(vec[j] == 0){
                    buracos.insert(j);
                }
            }
            if(!buracos.empty()){
                cout<<*buracos.begin()<<' ';
            }
            else{
                cout<<2e5<<' ';
            }
        }
        else{
            if(fila.front()<2e5){
                vec[fila.front()]--;
                if(vec[fila.front()] == 0){
                    buracos.insert(fila.front());
                }
            }
            fila.pop();

            if(aux < 2e5){
                vec[aux]++;
                if(vec[aux] == 1){
                    buracos.erase(aux);
                }
            }
            fila.push(aux);

            if(!buracos.empty()){
                cout<<*buracos.begin()<<' ';
            }
            else{
                cout<<2e5<<' ';
            }   
        }
    }
    return 0;
}