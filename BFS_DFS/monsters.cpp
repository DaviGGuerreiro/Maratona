#include<bits/stdc++.h>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char re[] = {'D','U','R','L'};
int n, m;
int numero = 1;
pair<int,int> comeco;
bool valid(int& y, int& x){
    return y>0 && y<=n && x>0 && x<=m;
}
pair<int,int> bfs(queue<pair<int,int>>& fila, vector<vector<char>>& vec, vector<vector<pair<char,char>>>& vis){
    pair<int,int> aux;
    while(!fila.empty() || comeco.first != -1){
        if(comeco.first == -1){
            aux = fila.front();
            fila.pop();
        }
        else{
            aux = comeco;
            comeco.first = -1;
        }

        if(vis[aux.first][aux.second].first == 'A' && (aux.second == 1 || aux.second == m ||aux.first == 1 || aux.first == n)){
            return aux;
        }

        for(int i=0;i<4;i++){
            int ax = aux.second + dx[i];
            int ay = aux.first + dy[i];
            if(valid(ay, ax) && vec[ay][ax] != '#' && vec[ay][ax] != 'M' && vec[ay][ax] != vec[aux.first][aux.second]){
                vis[ay][ax].first = vis[aux.first][aux.second].first;
                fila.push({ay,ax});
                if(vec[aux.first][aux.second] == 'A'){
                    numero++;
                }
                if(vec[ay][ax] != 'A'){
                   vis[ay][ax].second = re[i];
                }
                else{numero--;}
                vec[ay][ax] = vec[aux.first][aux.second];
            }
        }
        if(numero == 0){
            return {-1,-1};
        }
    }
    return {-1,-1};
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    queue<pair<int,int>> fila;
    vector<vector<char>> vec (n+1, vector<char> (m+1));
    vector<vector<pair<char,char>>> visitados (n+1, vector<pair<char,char>> (m+1, {'x','o'})); 
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>vec[i][j];
            if(vec[i][j] == 'M'){
                visitados[i][j].first = 'M';
                fila.push({i,j});
            }
            else if(vec[i][j] == 'A'){
                visitados[i][j].first = 'A';
                comeco = {i,j};
            }
        }
    }
    pair<int,int> b = bfs(fila, vec, visitados);
    if(b.first != -1){
        cout<<"YES"<<'\n';
        stack<char> pilha;
        while(visitados[b.first][b.second].second != 'o'){
            char z = visitados[b.first][b.second].second;
            pilha.push(z);
            if(z == 'D'){b.first--;}
            else if(z == 'U'){b.first++;}
            else if(z == 'L'){b.second++;}
            else if(z == 'R'){b.second--;}
        }
        cout<<pilha.size()<<'\n';
        while(!pilha.empty()){
            cout<<pilha.top();
            pilha.pop();
        }
    }
    else{
        cout<<"NO";
    }

    return 0;
}