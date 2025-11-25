#include<bits/stdc++.h>
using namespace std;

vector<int> resposta;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int m, n;
    cin>>n>>m;
    int l, r;
    vector<vector<int>> vec (n+1);
    vector<int> deg (n+1, 0);
    for(int i=0;i<m;i++){
        cin>>l>>r;
        vec[l].push_back(r);
        deg[r]++;
    }
    vector<int> topo;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int x: vec[u]){
            deg[x]--;
            if(deg[x] == 0){q.push(x);}
        }
    }
    if((int)topo.size() == n){
        for(int x : topo){
            cout<<x<<" ";
        }
    } else{
        cout<<"IMPOSSIBLE";
    }

    return 0;
}
