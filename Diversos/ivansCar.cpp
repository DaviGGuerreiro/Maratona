#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> vec;
deque<pair<int,int>> fila;
vector<int> distancia;
int n, m;
int a, b;

void bfs(){
    distancia = vector<int> (n,1e9);
    distancia[a] = 0;
    pair<int,int> aux;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop_front();
        if(aux.first == b){
            return;
        }
        for(auto it: vec[aux.first]){
            if((it.second == aux.second || (aux.second == 2 )) && distancia[aux.first] < distancia[it.first]){
                distancia[it.first] = distancia[aux.first];
                fila.push_front({it.first, it.second});
            }
            else if(it.second != aux.second && distancia[aux.first] < distancia[it.first]){
                distancia[it.first] = distancia[aux.first] + 1;
                fila.push_back({it.first, it.second});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    vec = vector<vector<pair<int,int>>> (n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--; 
        b--;
        vec[a].push_back({b,0});
        vec[b].push_back({a,1});
    }
    cin>>a>>b;
    a--; 
    b--;
    fila.push_front({a,2});
    bfs();
    cout<<distancia[b];
    return 0;
}