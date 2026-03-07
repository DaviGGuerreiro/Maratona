#include<bits/stdc++.h>
using namespace std;
int t;
void solve(int x, int n, int r){
    vector<vector<int>> vec (n);
    vector<int> deg (n,0);
    queue<int> q;
    vector<int> vet (n,1);
    vector<int> ord;
    priority_queue<int, vector<int>, greater<int>> pq;
    int a, b;
    for(int i=0;i<r;i++){
        cin>>a>>b;
        vec[b].push_back(a);
        deg[a]++;
    }
    for(int i=0;i<n;i++){
        if(deg[i] == 0){
            q.push(i);
            pq.push(i);
        }
    }
    cout<<"Scenario #"<<x<<":\n";
    int maior = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: vec[u]){
            deg[v]--;
            if(deg[v] == 0){
                q.push(v);
                vet[v] = vet[u] + 1;
                if(vet[v] > maior){
                    while(!pq.empty()){
                        cout<<maior<<" "<<pq.top()<<'\n';
                        pq.pop();
                    }
                    maior++;
                }
                pq.push(v);
            } 
        }
    }
    while(!pq.empty()){
        cout<<maior<<" "<<pq.top()<<'\n';
        pq.pop();
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int x;
    int n, r;
    cin>>t;
    x = 1;
    while(t--){
        cin>>n>>r;
        solve(x,n,r);
        x++;
    }
    return 0;
}