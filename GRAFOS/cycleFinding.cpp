#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<tuple<int,int,int>> vec;
vector<ll> dist(2501, 1e17);
vector<int> pai(2501,1);

void bellmanford(){
    dist[0] = 0;
    for(int i=0;i<n;i++){
        for(auto [u,v,w]: vec){
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                pai[v] = u;
            }
        }
    }
    bool ciclo = false;
    int aux;
    for(auto [u,v,w]: vec){
        if(dist[v] > dist[u] + w){
            ciclo = true;
            aux = v;
            pai[v] = u;
            for(int i=0;i<n;i++){
                aux = pai[aux];
            }
            break;
        }
    }
    if(ciclo){
        cout<<"YES\n";
        stack<int> res;
        res.push(aux);
        int aux2 = aux;
        while(true){
            aux = pai[aux];
            res.push(aux);
            if(aux == aux2){
                break;
            }
        }
        while(!res.empty()){
            cout<<res.top()<<" ";
            res.pop();
        }
    }
    else{
        cout<<"NO";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        vec.push_back({a,b,c});
    }
    for(int i=1;i<=n;i++){
        vec.push_back({0,i,0});
    }
    bellmanford();
    return 0;
}