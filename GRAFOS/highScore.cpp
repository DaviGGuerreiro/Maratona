#include<bits/stdc++.h>
using namespace std;
//tipos
using ll = long long;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
//loops
#define FOR(i,n) for(int i=0; i<(int)(n); i++)
#define FOR1(i,n) for(int i=1; i<=(int)(n); i++)
#define FORA(x,a) for(auto &x : a)
//Sorts
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
//debug
#define dbg(x) cerr << #x << " = " << x << "\n" 

//  ll aux = LLONG_MAX;
//  int a = INT_MAX;
int n, m;
vector<ll> dist (2501, -1e16);
bool cicle = false;
ll maximo = 0;

void dfs(int comeco, vector<vector<pii>>& vec, vector<bool>& visit){
    visit[comeco] = true;
    for(auto [u,v] : vec[comeco]){
        if(visit[u] == false){
            dfs(u,vec,visit);
        }
    }
}

void bellmanford(vector<vector<pii>>& vec, vector<bool>& visit){
    dist[1] = 0;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<=n;j++){
            if(visit[j] == true){
                for(auto [u,v]: vec[j]){
                    if(visit[u] == true && dist[u] < dist[j] + v){
                        dist[u] = dist[j] + v;
                    }
                }
            }
        }
    }
    vector<bool> vet(n+1,false);
    for(int j=1;j<=n;j++){
        if(visit[j]==true){
            for(auto [u,v]: vec[j]){
                if(visit[u] == true && dist[u] < dist[j] + v){
                    vet[u] = true;
                }
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=1;j<=n;j++){
            if(visit[j] == true && vet[j] == true){
                for(auto [u,v]: vec[j]){
                    if(visit[u] == true){
                        vet[u] = true;
                    }
                }
            }
        }
    }
    cicle = vet[n];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    vector<bool> visit (n+1, false);
    vector<vector<pii>> vec (n+1);
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
    }
    dfs(1, vec, visit);
    bellmanford(vec, visit);
    if(cicle){
        cout<<"-1";
    }
    else{
        cout<<dist[n];
    }
    return 0;
}