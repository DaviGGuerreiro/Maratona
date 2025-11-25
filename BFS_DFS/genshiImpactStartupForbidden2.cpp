#include<bits/stdc++.h>
using namespace std;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int bfs(int y, int x, int tipo, vector<vector<pair<int,int>>>& vec){
    queue<pair<int,int>> fila;
    map<pair<int,int>,bool> mapa;
    int r = 1;
    fila.push({y,x});
    mapa[{y,x}] = true;
    while(!fila.empty()){
        auto aux = fila.front();
        fila.pop();
        for(int i=0;i<4;i++){
            int ax = aux.second + dx[i];
            int ay = aux.first + dy[i];
            if((ax >= 1 && ax <=19) && (ay >= 1 && ay <=19)){
                if(vec[ay][ax].second == tipo){
                    if(vec[ay][ax].first != 0){
                        return 0;
                    }
                    else{
                        if(!mapa[{ay,ax}]){
                            fila.push({ay,ax});
                            mapa[{ay,ax}] = true;
                            r++;
                        }
                    }
                }
            }
        }
    }
    return r;
}

void bfs2(int y, int x, int tipo, vector<vector<pair<int,int>>>& vec){
    queue<pair<int,int>> fila;
    fila.push({y,x});
    vec[y][x].second = -1;
    while(!fila.empty()){
        auto aux = fila.front();
        fila.pop();
        for(int i=0;i<4;i++){
            int ax = aux.second + dx[i];
            int ay = aux.first + dy[i];
            if((ax >= 1 && ax <=19) && (ay >= 1 && ay <=19)){
                if(vec[ay][ax].second == tipo){
                    fila.push({ay,ax});
                    vec[ay][ax].second = -1;
                }
                else if(vec[ay][ax].second != -1){
                    vec[ay][ax].first ++;
                }
            }
        }
    }
    return;
}

pair<int,int> verif(int& a, int& b, int& tipo, vector<vector<pair<int,int>>>& vec){
    int s = 0;
    int z = 0;
    vec[b][a].second = tipo;
    for(int i=0; i<4; i++){
        int ax = a + dx[i];
        int ay = b + dy[i];
        if((ax >= 1 && ax <=19) && (ay >= 1 && ay <=19)){
            if(vec[ay][ax].second == -1){
                vec[b][a].first ++;
            }
            else if(vec[ay][ax].second != tipo){
                vec[ay][ax].first--;
                if(vec[ay][ax].first == 0){
                    int tipo_aux;
                    if(tipo == 0){
                        tipo_aux = 1;
                    } else{
                        tipo_aux = 0;
                    }
                    //bfs pra saber se os vizinhos dele que compartilham o mesmo tipo tambem são =0, se sim printa todos os nós
                    int g = bfs(ay,ax,tipo_aux,vec);
                    if(g!=0){
                        s = s + g;
                        bfs2(ay,ax,tipo_aux,vec);
                    }
                }
            }
            else{
                vec[ay][ax].first--;
            }
        }
    }
    if(vec[b][a].first == 0){
        z = bfs(b,a,tipo,vec);
        if(z!=0){
            bfs2(b,a,tipo,vec);
        }
    }
    return {s,z};
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int m;
    cin>>m;
    int a, b;
    int tipo;
    vector<vector<pair<int,int>>> vec (20, vector<pair<int,int>> (20,{0,-1}));
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        if(i%2 == 0){tipo = 1;}
        else{tipo = 0;}
        auto aux = verif(b, a, tipo, vec);
        if(tipo==0){cout<<aux.second<<" "<<aux.first<<'\n';}
        else{cout<<aux.first<<" "<<aux.second<<'\n';}
    }
    return 0;
}
