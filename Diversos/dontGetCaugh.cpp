#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<char,int>>> vec;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

bool bfs(){
    if(vec[0][0].first != '.') return false;
    vec[0][0].first = 'X';
    if(n == 1 && m == 1) return true;
    queue<pair<int,int>> fila;
    fila.push({0,0});
    pair<int,int> aux;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop();
        for(int i = 0;i<4;i++){
            int x = aux.second + dx[i];
            int y = aux.first + dy[i];
            if(x >=0 && y>=0 && x<m && y<n && vec[y][x].second == -1 && vec[y][x].first == '.'){
                vec[y][x].second = i;
                if(y == n-1 && x == m-1){
                    while(vec[y][x].second != -1){
                        vec[y][x].first = 'X';
                        if(vec[y][x].second == 0){
                            y--;
                        }
                        else if(vec[y][x].second == 1){
                            y++;
                        }
                        else if(vec[y][x].second == 2){
                            x--;
                        }
                        else{
                            x++;
                        }
                    }
                    return true;
                }
                fila.push({y,x});
            }
        }
    }
    return false;
}

void solve(){
    int k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j].first == '^'){
                k = i-1;
                while(k>=0){
                    if(vec[k][j].first != '.' && vec[k][j].first != '-'){
                        break;
                    }
                    else{
                        vec[k][j].first = '-';
                    }
                    k--;
                }
            }
            else if(vec[i][j].first == '<'){
                k = j-1;
                while(k>=0){
                    if(vec[i][k].first != '.' && vec[i][k].first != '-'){
                        break;
                    }
                    else{
                        vec[i][k].first = '-';
                    }
                    k--;
                }
            }
            else if(vec[i][j].first == 'v'){
                k = i+1;
                while(k<n){
                    if(vec[k][j].first != '.' && vec[k][j].first != '-'){
                        break;
                    }
                    else{
                        vec[k][j].first = '-';
                    }
                    k++;
                }
            }
            else if(vec[i][j].first == '>'){
                k = j+1;
                while(k<m){
                    if(vec[i][k].first != '.' && vec[i][k].first != '-'){
                        break;
                    }
                    else{
                        vec[i][k].first = '-';
                    }
                    k++;
                }
            }
        }
    }
    if(bfs()){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j].first == '-'){
                    cout<<'.';
                }
                else{
                    cout<<vec[i][j].first;
                }
            }
            cout<<'\n';
        }
    }
    else{
        cout<<-1;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    vec = vector<vector<pair<char,int>>> (n, vector<pair<char,int>> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j].first;
            vec[i][j].second = -1;
        }
    }
    solve();
    return 0;
}