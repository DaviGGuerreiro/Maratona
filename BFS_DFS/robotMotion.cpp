#include<bits/stdc++.h>
using namespace std;
int a,b,c;
pair<int, int> N = {0,-1};
pair<int, int> S = {0,1};
pair<int, int> W = {-1,0};
pair<int, int> E = {1,0};

bool valid(pair<int,int>& p){
    return p.first >= 0 && p.first < b && p.second >= 0 && p.second < a;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    char aux;
    cin>>a>>b>>c;
    while(a!=0 || b!=0 || c!=0){
        vector<vector<pair<int,int>>> vec (a, vector<pair<int,int>> (b));
        vector<vector<bool>> visit (a, vector<bool> (b,false));
        for(int i = 0;i<a;i++){
            for(int j = 0;j<b;j++){
                cin>>aux;
                if(aux == 'N'){vec[i][j] = N;}
                else if(aux == 'S'){vec[i][j] = S;}
                else if(aux == 'W'){vec[i][j] = W;}
                else if(aux == 'E'){vec[i][j] = E;}
            }
        }
        int tamanho = 0;
        int x, y;
        bool flag = true;
        pair<int,int> init = {c-1,0};
        map<pair<int,int>, int> mapa;
        visit[0][c-1] = true;
        while(valid(init)){
            x = init.first;
            y = init.second;
            mapa[{y,x}] = tamanho;
            init.first = init.first + vec[y][x].first;
            init.second = init.second + vec[y][x].second;
            if(valid(init)){
                if(visit[init.second][init.first] == true){
                    flag = false;
                    cout<<mapa[{init.second,init.first}]<<" step(s) before a loop of "<<tamanho+1-mapa[{init.second,init.first}]<<" step(s)\n";
                    break;
                }
                visit[init.second][init.first] = true;
            }
            tamanho++;
        }

        if(flag){
            cout<<tamanho<<" step(s) to exit\n";
        }

        cin>>a>>b>>c;
    }
    return 0;
}