#include<bits/stdc++.h>
using namespace std;

int a, b;
int x, y;

const int dx[] = {1,1,-1,-1,2,2,-2,-2};
const int dy[] = {2,-2,2,-2,1,-1,1,-1};

void bfs(){
    char c1 = a + 97;
    char f1 = b + 97;
    if(a == b && x == y){
        cout<<"To get from "<<c1<<x+1<<" to "<<f1<<y+1<<" takes "<<0<<" knight moves.\n";
        return;
    }
    vector<vector<int>> tabuleiro (8, vector<int> (8,1e9));
    queue<pair<int,int>> fila;
    tabuleiro[x][a] = 0;
    fila.push({a,x});
    pair<int,int> aux;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop();
        for(int i=0; i<8;i++){
            int ax = aux.second + dx[i];
            int ay = aux.first + dy[i];
            if(ax < 8 && ax>=0 && ay<8 && ay>=0){
                if(ax == y && ay == b){
                    cout<<"To get from "<<c1<<x+1<<" to "<<f1<<y+1<<" takes "<<tabuleiro[aux.second][aux.first] + 1<<" knight moves.\n";
                    return;
                }
                else if(tabuleiro[ax][ay] == 1e9){
                    tabuleiro[ax][ay] = tabuleiro[aux.second][aux.first] + 1;
                    fila.push({ay,ax});
                }
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie();
    char st1, st2;
    while(cin>>st1>>x>>st2>>y){
        a = st1 - 97;
        b = st2 - 97;
        x--;
        y--;
        bfs();
    }
    return 0;
}