#include<bits/stdc++.h>
using namespace std;
int n,k,d;
map<pair<int,int>,int> mapa;
void bfs(queue<int>& fila, vector<vector<int>>& v, vector<pair<int,int>>& dist){
    while(!fila.empty()){
        int aux = fila.front();
        fila.pop();
        for(int x : v[aux]){
            if(dist[x].first == -1){
                dist[x].first = dist[aux].first + 1;
                dist[x].second = dist[aux].second;
                if(dist[x].first != d){
                    fila.push(x);
                }
                else{
                    for(int y : v[x]){
                        if(y != aux){
                            if(dist[y].first == -1){
                                if(mapa[{y,x}] != -1){
                                    cout<<mapa[{y,x}]<<" ";
                                    mapa[{x,y}] = -1;
                                }
                            }
                        }
                    }
                }
            }
            else if(dist[x].second != dist[aux].second && dist[x].first >= 0){
                if(mapa[{x,aux}] != -1){
                    cout<<mapa[{x, aux}]<<" ";
                    mapa[{aux,x}] = -1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int a, b;
    cin>>n>>k>>d;
    int r = 0;
    map<int,int> mapa1;
    vector<vector<int>> vec (n+1);
    vector<pair<int,int>> vis (n+1, {-1, -1});
    queue<int> stations;
    for(int i=1;i<=k;i++){
        cin>>a;
        if(mapa1[a] == 0){
            stations.push(a);
            vis[a].second = a;
            vis[a].first = 0;
            r++;
            mapa1[a] = 1;
        }   
    }
    for(int i=1;i<n;i++){
        cin>>a>>b;
        mapa[{a,b}] = i;
        mapa[{b,a}] = i;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    cout<<r-1<<'\n';
    if(d != 0){
        bfs(stations, vec, vis);
    }
    else{
        for(int i = 1; i < n; i++){
            cout<<i<<" ";
        }
    }

    return 0;
}